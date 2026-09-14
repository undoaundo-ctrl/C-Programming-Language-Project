#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_Q 6

void toLower(char *s) { while (*s) { *s = (char) tolower((unsigned char) *s); s++; } }

int main() {
    const char *prompts[NUM_Q] = {"Salt and", "Peanut butter and", "Bread and", "Thunder and", "Black and", "Sun and"};
    const char *answers[NUM_Q] = {"pepper", "jelly", "butter", "lightning", "white", "moon"};
    char guess[50];
    int score = 0, i;

    printf("=== Word Association ===\nComplete the common pair.\n");

    for (i = 0; i < NUM_Q; i++) {
        printf("\n%s ___? > ", prompts[i]);
        scanf("%49s", guess);
        toLower(guess);

        if (strcmp(guess, answers[i]) == 0) { printf("Correct!\n"); score++; }
        else printf("A common answer: %s\n", answers[i]);
    }

    printf("\nFinal score: %d/%d\n", score, NUM_Q);
    return 0;
}
