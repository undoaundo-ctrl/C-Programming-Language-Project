#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_Q 5

void toLower(char *s) { while (*s) { *s = (char) tolower((unsigned char) *s); s++; } }

int main() {
    const char *sounds[NUM_Q] = {"Moo", "Oink", "Neigh", "Quack", "Baa"};
    const char *answers[NUM_Q] = {"cow", "pig", "horse", "duck", "sheep"};
    char guess[50];
    int score = 0, i;

    printf("=== Animal Sound Quiz ===\nWhich animal makes this sound?\n");

    for (i = 0; i < NUM_Q; i++) {
        printf("\n\"%s\" > ", sounds[i]);
        scanf("%49s", guess);
        toLower(guess);

        if (strcmp(guess, answers[i]) == 0) { printf("Correct!\n"); score++; }
        else printf("Answer: %s\n", answers[i]);
    }

    printf("\nFinal score: %d/%d\n", score, NUM_Q);
    return 0;
}
