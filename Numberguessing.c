#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    long long guess;
    long long attempts = 0;

    srand((unsigned)time(NULL));

    long long secret =
        ((long long)rand() << 32 | rand()) % 1000000000LL + 1;

    printf("=== NUMBER GUESSING GAME ===\n");
    printf("Guess the number from 1 to 1,000,000,000!\n");

    while (1) {
        printf("\nEnter your guess: ");

        if (scanf("%lld", &guess) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n');
            continue;
        }

        if (guess < 1 || guess > 1000000000LL) {
            printf("Enter a number between 1 and 1,000,000,000.\n");
            continue;
        }

        attempts++;

        if (guess < secret)
            printf("Too low!\n");
        else if (guess > secret)
            printf("Too high!\n");
        else {
            printf("\nCORRECT!\n");
            printf("Attempts: %lld\n", attempts);
            break;
        }
    }

    return 0;
}
