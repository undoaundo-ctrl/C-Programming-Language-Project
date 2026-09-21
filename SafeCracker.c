#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int combo[3], guess[3], attempts = 0, i, correctDigits;

    srand((unsigned int) time(NULL));
    for (i = 0; i < 3; i++) combo[i] = rand() % 10;

    printf("=== Safe Cracker ===\nCrack the 3-digit combination (0-9 each). Hints tell how many digits are correct (position matters).\n");

    while (1) {
        attempts++;
        printf("\nAttempt %d - enter 3 digits: ", attempts);
        for (i = 0; i < 3; i++) if (scanf("%d", &guess[i]) != 1) return 1;

        correctDigits = 0;
        for (i = 0; i < 3; i++) if (guess[i] == combo[i]) correctDigits++;

        printf("Correct digits in right position: %d\n", correctDigits);

        if (correctDigits == 3) {
            printf("\nSAFE CRACKED in %d attempts!\n", attempts);
            break;
        }
    }

    return 0;
}
