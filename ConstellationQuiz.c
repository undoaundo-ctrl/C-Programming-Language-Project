#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_Q 4

void toLower(char *s) { while (*s) { *s = (char) tolower((unsigned char) *s); s++; } }

int main() {
    const char *hints[NUM_Q] = {
        "This constellation looks like a hunter with a belt of three stars.",
        "This constellation is also known as the Great Bear, containing the Big Dipper.",
        "This constellation is named after a mythical winged horse.",
        "This zodiac constellation is represented by a lion."
    };
    const char *answers[NUM_Q] = {"orion", "ursa major", "pegasus", "leo"};
    char guess[50];
    int score = 0, i;

    printf("=== Constellation Quiz ===\n");

    for (i = 0; i < NUM_Q; i++) {
        printf("\n%s\n> ", hints[i]);
        getchar();
        fgets(guess, sizeof(guess), stdin);
        guess[strcspn(guess, "\n")] = 0;
        toLower(guess);

        if (strcmp(guess, answers[i]) == 0) { printf("Correct!\n"); score++; }
        else printf("Answer: %s\n", answers[i]);
    }

    printf("\nFinal score: %d/%d\n", score, NUM_Q);
    return 0;
}
