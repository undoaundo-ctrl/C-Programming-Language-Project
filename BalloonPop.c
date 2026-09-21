#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numBalloons = 10, popPosition, guess, score = 0, rounds = 5, r;

    srand((unsigned int) time(NULL));
    printf("=== Balloon Pop ===\nGuess which balloon (1-%d) will pop!\n", numBalloons);

    for (r = 1; r <= rounds; r++) {
        popPosition = 1 + rand() % numBalloons;
        printf("\nRound %d - Pick a balloon (1-%d): ", r, numBalloons);
        if (scanf("%d", &guess) != 1) continue;

        if (guess == popPosition) { printf("POP! You got it!\n"); score++; }
        else printf("That one didn't pop. Balloon %d was the popper.\n", popPosition);
    }

    printf("\nFinal score: %d/%d\n", score, rounds);
    return 0;
}
