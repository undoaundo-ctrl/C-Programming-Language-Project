#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_Q 5

void toLower(char *s) { while (*s) { *s = (char) tolower((unsigned char) *s); s++; } }

int main() {
    const char *questions[NUM_Q] = {
        "How many centimeters in a meter?",
        "How many grams in a kilogram?",
        "How many milliliters in a liter?",
        "How many inches in a foot?",
        "How many seconds in a minute?"
    };
    const char *answers[NUM_Q] = {"100", "1000", "1000", "12", "60"};
    char guess[50];
    int score = 0, i;

    printf("=== Unit Conversion Quiz ===\n");

    for (i = 0; i < NUM_Q; i++) {
        printf("\n%s > ", questions[i]);
        scanf("%49s", guess);
        toLower(guess);

        if (strcmp(guess, answers[i]) == 0) { printf("Correct!\n"); score++; }
        else printf("Answer: %s\n", answers[i]);
    }

    printf("\nFinal score: %d/%d\n", score, NUM_Q);
    return 0;
}
