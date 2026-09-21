#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, n, factor, guessCount = 0, correctFactors = 0;

    srand((unsigned int) time(NULL));
    num = 20 + rand() % 80;
    n = num;

    printf("=== Prime Factorization ===\nFind all prime factors of %d, one at a time. Type 0 when done.\n", num);

    while (1) {
        printf("\nRemaining value: %d\nEnter a prime factor (or 0 to stop): ", n);
        if (scanf("%d", &factor) != 1) break;
        if (factor == 0) break;

        guessCount++;
        if (n % factor == 0) {
            printf("Correct factor!\n");
            n /= factor;
            correctFactors++;
        } else {
            printf("Not a factor of the remaining value.\n");
        }

        if (n == 1) { printf("\nFully factored!\n"); break; }
    }

    printf("\nYou found %d correct factors in %d guesses. (Remaining value: %d)\n", correctFactors, guessCount, n);
    return 0;
}
