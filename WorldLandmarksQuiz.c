#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_Q 5

void toLower(char *s) { while (*s) { *s = (char) tolower((unsigned char) *s); s++; } }

int main() {
    const char *questions[NUM_Q] = {
        "Which country is the Eiffel Tower in?",
        "Which country is the Great Wall located in?",
        "Which country is Machu Picchu located in?",
        "Which country is the Colosseum located in?",
        "Which country is the Taj Mahal located in?"
    };
    const char *answers[NUM_Q] = {"france", "china", "peru", "italy", "india"};
    char guess[100];
    int score = 0, i;

    printf("=== World Landmarks Quiz ===\n");

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
