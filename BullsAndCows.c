#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    char secret[5], guess[10];
    int digits[10] = {0}, d, i, bulls, cows, attempt = 0;

    srand((unsigned int) time(NULL));

    i = 0;
    while (i < 4) {
        d = rand() % 10;
        if (!digits[d]) { digits[d] = 1; secret[i] = (char) ('0' + d); i++; }
    }
    secret[4] = '\0';

    printf("=== Bulls and Cows ===\nGuess the 4-digit number with unique digits.\n");
    printf("Bulls = right digit right place. Cows = right digit wrong place.\n");

    while (1) {
        attempt++;
        printf("\nAttempt %d - guess: ", attempt);
        scanf("%9s", guess);
        if ((int) strlen(guess) != 4) { printf("Enter exactly 4 digits.\n"); attempt--; continue; }

        bulls = 0; cows = 0;
        for (i = 0; i < 4; i++) {
            if (guess[i] == secret[i]) bulls++;
            else if (strchr(secret, guess[i]) != NULL) cows++;
        }

        printf("Bulls: %d, Cows: %d\n", bulls, cows);

        if (bulls == 4) {
            printf("\nYou got it in %d attempts!\n", attempt);
            break;
        }
    }

    return 0;
}
