#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_Q 5

void toLower(char *s) { while (*s) { *s = (char) tolower((unsigned char) *s); s++; } }

int main() {
    const char *riddles[NUM_Q] = {
        "What has keys but no locks, space but no room, and you can enter but not go inside?",
        "The more you take, the more you leave behind. What am I?",
        "What has a heart that doesn't beat?",
        "What gets wetter the more it dries?",
        "What can travel around the world while staying in a corner?"
    };
    const char *answers[NUM_Q] = {"keyboard", "footsteps", "artichoke", "towel", "stamp"};
    char guess[100];
    int score = 0, i;

    printf("=== Riddle Quiz ===\n");

    for (i = 0; i < NUM_Q; i++) {
        printf("\nRiddle %d: %s\n> ", i + 1, riddles[i]);
        getchar();
        fgets(guess, sizeof(guess), stdin);
        guess[strcspn(guess, "\n")] = 0;
        toLower(guess);

        if (strcmp(guess, answers[i]) == 0) { printf("Correct!\n"); score++; }
        else printf("Not quite! Answer: %s\n", answers[i]);
    }

    printf("\nFinal score: %d/%d\n", score, NUM_Q);
    return 0;
}
