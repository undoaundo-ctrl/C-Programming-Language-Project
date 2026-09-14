#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_Q 5

void toLower(char *s) { while (*s) { *s = (char) tolower((unsigned char) *s); s++; } }

int main() {
    const char *descriptions[NUM_Q] = {
        "Red, white, and blue with 50 stars and 13 stripes",
        "Red circle on a white background",
        "Red, white, and green vertical stripes with an eagle emblem",
        "Blue with a white cross, resembling other Nordic flags",
        "Green, yellow, and red horizontal stripes with a black star"
    };
    const char *answers[NUM_Q] = {"united states", "japan", "mexico", "finland", "ghana"};
    char guess[100];
    int score = 0, i;

    printf("=== Flag Quiz ===\nGuess the country from the flag description.\n");

    for (i = 0; i < NUM_Q; i++) {
        printf("\nFlag %d: %s\n> ", i + 1, descriptions[i]);
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
