#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_Q 5

void toLower(char *s) { while (*s) { *s = (char) tolower((unsigned char) *s); s++; } }

int main() {
    const char *questions[NUM_Q] = {
        "What planet is known as the Red Planet?",
        "What gas do plants absorb from the atmosphere?",
        "What is the chemical symbol for gold?",
        "What force pulls objects toward Earth?",
        "What is the powerhouse of the cell?"
    };
    const char *answers[NUM_Q] = {"mars", "carbon dioxide", "au", "gravity", "mitochondria"};
    char guess[100];
    int score = 0, i;

    printf("=== Science Trivia Quiz ===\n");

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
