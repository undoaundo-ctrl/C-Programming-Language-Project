#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_Q 5

void toLower(char *s) { while (*s) { *s = (char) tolower((unsigned char) *s); s++; } }

int main() {
    const char *questions[NUM_Q] = {
        "What is the closest star to Earth?",
        "What is the largest planet in our solar system?",
        "What galaxy do we live in?",
        "What is the name of Earth's only natural satellite?",
        "What planet is known for its prominent rings?"
    };
    const char *answers[NUM_Q] = {"the sun", "jupiter", "milky way", "the moon", "saturn"};
    char guess[100];
    int score = 0, i;

    printf("=== Space Trivia ===\n");

    for (i = 0; i < NUM_Q; i++) {
        printf("\nQ%d: %s\n> ", i + 1, questions[i]);
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
