#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, flip, streak = 0, best = 0;
    char again;

    srand((unsigned int) time(NULL));
    printf("=== Coin Flip Streak ===\nGuess heads (1) or tails (0). Build your streak!\n");

    do {
        printf("\nYour guess (1=heads, 0=tails): ");
        if (scanf("%d", &guess) != 1 || (guess != 0 && guess != 1)) {
            printf("Invalid.\n");
            continue;
        }
        flip = rand() % 2;
        printf("Coin landed on: %s\n", flip ? "Heads" : "Tails");

        if (flip == guess) {
            streak++;
            if (streak > best) best = streak;
            printf("Correct! Streak: %d\n", streak);
        } else {
            printf("Wrong! Streak broken. Final streak was %d.\n", streak);
            streak = 0;
        }

        printf("Flip again? (y/n): ");
        scanf(" %c", &again);
    } while (again == 'y' || again == 'Y');

    printf("\nBest streak: %d\n", best);
    return 0;
}
