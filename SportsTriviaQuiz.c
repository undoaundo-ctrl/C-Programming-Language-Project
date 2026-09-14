#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_Q 5

void toLower(char *s) { while (*s) { *s = (char) tolower((unsigned char) *s); s++; } }

int main() {
    const char *questions[NUM_Q] = {
        "How many players are on a standard soccer team on the field?",
        "How many points is a touchdown worth in American football?",
        "In tennis, what is a score of zero called?",
        "How many rings are on the Olympic flag?",
        "How many holes are played in a standard round of golf?"
    };
    const char *answers[NUM_Q] = {"11", "6", "love", "5", "18"};
    char guess[100];
    int score = 0, i;

    printf("=== Sports Trivia Quiz ===\n");

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
