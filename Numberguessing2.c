#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    unsigned long long guess, secret, attempts = 0;

    srand((unsigned)time(NULL));

    secret = ((unsigned long long)rand() << 32 | rand()) % 1000000000000ULL + 1;

    printf("=== NUMBER GUESSING GAME ===\n");
    printf("Guess the number from 1 to 1,000,000,000,000!\n");

    while (1) {
        printf("\nEnter your guess: ");

        if (scanf("%llu", &guess) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n');
            continue;
        }

        if (guess < 1 || guess > 1000000000000ULL) {
            printf("Number must be between 1 and 1,000,000,000,000.\n");
            continue;
        }

        attempts++;

        if (guess < secret)
            printf("Too low!\n");
        else if (guess > secret)
            printf("Too high!\n");
        else {
            printf("\nCORRECT!\n");
            printf("Attempts: %llu\n", attempts);
            break;
        }
    }

    return 0;
}
