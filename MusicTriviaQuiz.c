#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_Q 5

void toLower(char *s) { while (*s) { *s = (char) tolower((unsigned char) *s); s++; } }

int main() {
    const char *questions[NUM_Q] = {
        "How many strings does a standard guitar have?",
        "What instrument has 88 keys?",
        "What is the term for singing without instrumental accompaniment?",
        "What family of instruments does the violin belong to?",
        "How many members are typically in a string quartet?"
    };
    const char *answers[NUM_Q] = {"6", "piano", "acapella", "strings", "4"};
    char guess[100];
    int score = 0, i;

    printf("=== Music Trivia Quiz ===\n");

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
