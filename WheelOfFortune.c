#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int main() {
    const char *phrase = "PROGRAMMING IS FUN";
    char display[100];
    char guess;
    int len = (int) strlen(phrase);
    int i, guessesLeft = 8, revealed = 0, totalLetters = 0;

    srand((unsigned int) time(NULL));

    for (i = 0; i < len; i++) {
        if (phrase[i] == ' ') { display[i] = ' '; }
        else { display[i] = '_'; totalLetters++; }
    }
    display[len] = '\0';

    printf("=== Wheel of Fortune ===\nGuess the phrase, one letter at a time. %d wrong guesses allowed.\n", guessesLeft);

    while (revealed < totalLetters && guessesLeft > 0) {
        printf("\n%s\n", display);
        printf("Guess a letter: ");
        if (scanf(" %c", &guess) != 1) break;
        guess = (char) toupper((unsigned char) guess);

        {
            int found = 0;
            for (i = 0; i < len; i++) {
                if (phrase[i] == guess && display[i] == '_') {
                    display[i] = guess;
                    revealed++;
                    found = 1;
                }
            }
            if (!found) { printf("Not in the phrase!\n"); guessesLeft--; }
            else printf("Nice find!\n");
        }
    }

    if (revealed == totalLetters) printf("\nSolved! The phrase was: %s\n", phrase);
    else printf("\nOut of guesses! The phrase was: %s\n", phrase);

    return 0;
}
