#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define CODE_LEN 4

int main() {
    char letters[] = "ABCDEF";
    char secret[CODE_LEN], guess[CODE_LEN];
    int i, j, attempt, exact, partial, usedSecret[CODE_LEN], usedGuess[CODE_LEN];

    srand((unsigned int) time(NULL));
    for (i = 0; i < CODE_LEN; i++) secret[i] = letters[rand() % 6];

    printf("=== Code Breaker ===\nGuess the %d-letter code using letters A-F.\n", CODE_LEN);

    for (attempt = 1; attempt <= 10; attempt++) {
        printf("\nAttempt %d - enter %d letters (A-F) separated by spaces: ", attempt, CODE_LEN);
        for (i = 0; i < CODE_LEN; i++) {
            char c;
            if (scanf(" %c", &c) != 1) return 1;
            guess[i] = (char) toupper((unsigned char) c);
            usedSecret[i] = 0;
            usedGuess[i] = 0;
        }

        exact = 0;
        for (i = 0; i < CODE_LEN; i++) {
            if (guess[i] == secret[i]) { exact++; usedSecret[i] = 1; usedGuess[i] = 1; }
        }

        partial = 0;
        for (i = 0; i < CODE_LEN; i++) {
            if (usedGuess[i]) continue;
            for (j = 0; j < CODE_LEN; j++) {
                if (!usedSecret[j] && guess[i] == secret[j]) { partial++; usedSecret[j] = 1; break; }
            }
        }

        printf("Exact: %d, Partial: %d\n", exact, partial);

        if (exact == CODE_LEN) {
            printf("\nCode broken in %d attempts!\n", attempt);
            return 0;
        }
    }

    printf("\nOut of attempts! The code was: ");
    for (i = 0; i < CODE_LEN; i++) printf("%c ", secret[i]);
    printf("\n");

    return 0;
}
