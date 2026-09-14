#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rounds = 8, i, mole, guess, score = 0;

    srand((unsigned int) time(NULL));
    printf("=== Whack-a-Mole ===\nThe mole hides in hole 1-5. Guess where it is!\n");

    for (i = 1; i <= rounds; i++) {
        mole = 1 + rand() % 5;
        printf("\nRound %d - Which hole (1-5)? ", i);
        if (scanf("%d", &guess) != 1) continue;

        if (guess == mole) {
            printf("Whack! You got the mole!\n");
            score++;
        } else {
            printf("Missed! The mole was in hole %d.\n", mole);
        }
    }

    printf("\nFinal score: %d/%d\n", score, rounds);
    return 0;
}
