#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WORD_LEN 5
#define MAX_TRIES 6
#define WORD_COUNT 6

int main() {
    const char *words[WORD_COUNT] = {"apple", "grape", "mango", "peach", "lemon", "berry"};
    char secret[WORD_LEN + 1];
    char guess[20];
    int tries, i, won = 0;

    srand((unsigned int) time(NULL));
    strcpy(secret, words[rand() % WORD_COUNT]);

    printf("=== Wordle Clone ===\nGuess the %d-letter word. %d tries.\n", WORD_LEN, MAX_TRIES);
    printf("Feedback: G=correct spot, Y=wrong spot, _=not in word\n");

    for (tries = 1; tries <= MAX_TRIES; tries++) {
        printf("\nAttempt %d: ", tries);
        scanf("%19s", guess);

        if ((int) strlen(guess) != WORD_LEN) { printf("Word must be %d letters.\n", WORD_LEN); tries--; continue; }

        printf("Result: ");
        for (i = 0; i < WORD_LEN; i++) {
            if (guess[i] == secret[i]) printf("G");
            else if (strchr(secret, guess[i]) != NULL) printf("Y");
            else printf("_");
        }
        printf("\n");

        if (strcmp(guess, secret) == 0) { won = 1; break; }
    }

    if (won) printf("\nYou guessed it! The word was: %s\n", secret);
    else printf("\nOut of tries! The word was: %s\n", secret);

    return 0;
}
