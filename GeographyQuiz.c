#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_Q 6

void toLower(char *s) {
    while (*s) { *s = (char) tolower((unsigned char) *s); s++; }
}

int main() {
    const char *questions[NUM_Q] = {
        "What is the capital of France?",
        "What is the capital of Japan?",
        "What is the largest country by area?",
        "What is the longest river in the world?",
        "Which continent is the Sahara Desert on?",
        "What is the smallest country in the world?"
    };
    const char *answers[NUM_Q] = {
        "paris", "tokyo", "russia", "nile", "africa", "vatican city"
    };
    char guess[100];
    int score = 0, i;

    printf("=== Geography Quiz ===\n");

    for (i = 0; i < NUM_Q; i++) {
        printf("\nQ%d: %s\n> ", i + 1, questions[i]);
        getchar();
        fgets(guess, sizeof(guess), stdin);
        guess[strcspn(guess, "\n")] = 0;
        toLower(guess);

        if (strcmp(guess, answers[i]) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! Answer: %s\n", answers[i]);
        }
    }

    printf("\nFinal score: %d/%d\n", score, NUM_Q);
    return 0;
}
