#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    char secret[4];
    char guess[10];
    int digits[10] = {0}, d, i, strikes, balls, attempt = 0;

    srand((unsigned int) time(NULL));

    i = 0;
    while (i < 3) {
        d = rand() % 10;
        if (!digits[d]) { digits[d] = 1; secret[i] = (char) ('0' + d); i++; }
    }
    secret[3] = '\0';

    printf("=== Number Baseball ===\nGuess the 3-digit number with unique digits.\n");
    printf("Strike = right digit right place. Ball = right digit wrong place.\n");

    while (1) {
        attempt++;
        printf("\nAttempt %d - guess: ", attempt);
        scanf("%9s", guess);
        if ((int) strlen(guess) != 3) { printf("Enter exactly 3 digits.\n"); attempt--; continue; }

        strikes = 0; balls = 0;
        for (i = 0; i < 3; i++) {
            if (guess[i] == secret[i]) strikes++;
            else if (strchr(secret, guess[i]) != NULL) balls++;
        }

        printf("Strikes: %d, Balls: %d\n", strikes, balls);

        if (strikes == 3) {
            printf("\nHome run! You got it in %d attempts!\n", attempt);
            break;
        }
    }

    return 0;
}
