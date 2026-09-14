#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WORD_COUNT 8
#define MAX_LEN 20

void scrambleWord(char *word, char *scrambled) {
    int len = (int) strlen(word);
    int i, j;
    char temp[MAX_LEN];

    strcpy(temp, word);

    for (i = 0; i < len - 1; i++) {
        j = i + rand() % (len - i);
        char c = temp[i];
        temp[i] = temp[j];
        temp[j] = c;
    }

    strcpy(scrambled, temp);
}

int main() {
    const char *words[WORD_COUNT] = {
        "computer", "keyboard", "program", "variable",
        "function", "compiler", "developer", "software"
    };
    char scrambled[MAX_LEN];
    char guess[MAX_LEN];
    int score = 0, rounds = WORD_COUNT, i;

    srand((unsigned int) time(NULL));

    printf("=== Word Scramble ===\n");
    printf("Unscramble each word. You have %d rounds.\n", rounds);

    for (i = 0; i < rounds; i++) {
        char word[MAX_LEN];
        strcpy(word, words[i]);

        do {
            scrambleWord(word, scrambled);
        } while (strcmp(scrambled, word) == 0);

        printf("\nRound %d: %s\n", i + 1, scrambled);
        printf("Your guess: ");
        scanf("%19s", guess);

        if (strcmp(guess, word) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The word was: %s\n", word);
        }
    }

    printf("\n=== Game Over ===\n");
    printf("Final score: %d out of %d\n", score, rounds);

    return 0;
}
