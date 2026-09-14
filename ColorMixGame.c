#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_Q 4

void toLower(char *s) { while (*s) { *s = (char) tolower((unsigned char) *s); s++; } }

int main() {
    const char *questions[NUM_Q] = {
        "Red + Yellow = ?",
        "Blue + Yellow = ?",
        "Red + Blue = ?",
        "Red + Green + Blue = ?"
    };
    const char *answers[NUM_Q] = {"orange", "green", "purple", "white"};
    char guess[50];
    int score = 0, i;

    printf("=== Color Mixing Game ===\nWhat color do you get when you mix these?\n");

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
