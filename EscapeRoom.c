#include <stdio.h>
#include <string.h>

int main() {
    char answer[50];

    printf("=== Escape Room ===\n");
    printf("You wake up in a locked room. There's a note on the wall:\n");
    printf("\"I speak without a mouth and hear without ears. I have no body, but I come alive with wind. What am I?\"\n");
    printf("> ");
    scanf("%49s", answer);

    if (strcmp(answer, "echo") == 0 || strcmp(answer, "Echo") == 0) {
        printf("\nThe door clicks open! You solved the riddle and escaped!\n");
    } else {
        printf("\nWrong answer. The door stays locked. (Answer: echo)\n");
        return 0;
    }

    printf("\nYou find a second door with a keypad. It says: 'The sum of first 5 primes.'\n> ");
    {
        int guess;
        scanf("%d", &guess);
        if (guess == 28) { /* 2+3+5+7+11 */
            printf("\nCorrect! You've escaped the room! Congratulations!\n");
        } else {
            printf("\nIncorrect. You remain trapped. (Answer: 28)\n");
        }
    }

    return 0;
}
