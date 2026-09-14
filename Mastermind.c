#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CODE_LEN 4
#define MAX_GUESSES 10

int main() {
    int secret[CODE_LEN], guess[CODE_LEN];
    int i, j, attempt, exact, partial, usedSecret[CODE_LEN], usedGuess[CODE_LEN];

    srand((unsigned int) time(NULL));
    for (i = 0; i < CODE_LEN; i++) secret[i] = rand() % 6; /* digits 0-5 */

    printf("=== Mastermind ===\nGuess the %d-digit code (digits 0-5). %d attempts.\n", CODE_LEN, MAX_GUESSES);

    for (attempt = 1; attempt <= MAX_GUESSES; attempt++) {
        printf("\nAttempt %d - enter %d digits (0-5) separated by spaces: ", attempt, CODE_LEN);
        for (i = 0; i < CODE_LEN; i++) {
            if (scanf("%d", &guess[i]) != 1) return 1;
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

        printf("Exact matches: %d, Partial matches: %d\n", exact, partial);

        if (exact == CODE_LEN) {
            printf("\nYou cracked the code in %d attempts!\n", attempt);
            return 0;
        }
    }

    printf("\nOut of attempts! The code was: ");
    for (i = 0; i < CODE_LEN; i++) printf("%d ", secret[i]);
    printf("\n");

    return 0;
}
