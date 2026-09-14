#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_Q 6

void toLower(char *s) { while (*s) { *s = (char) tolower((unsigned char) *s); s++; } }

int main() {
    const char *elements[NUM_Q] = {"Hydrogen", "Oxygen", "Gold", "Iron", "Sodium", "Carbon"};
    const char *symbols[NUM_Q] = {"h", "o", "au", "fe", "na", "c"};
    char guess[20];
    int score = 0, i;

    printf("=== Periodic Table Quiz ===\nWhat is the chemical symbol for each element?\n");

    for (i = 0; i < NUM_Q; i++) {
        printf("\n%s > ", elements[i]);
        scanf("%19s", guess);
        toLower(guess);

        if (strcmp(guess, symbols[i]) == 0) { printf("Correct!\n"); score++; }
        else printf("Answer: %s\n", symbols[i]);
    }

    printf("\nFinal score: %d/%d\n", score, NUM_Q);
    return 0;
}
