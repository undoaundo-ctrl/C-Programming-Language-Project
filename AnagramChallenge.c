#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_Q 5

void toLower(char *s) { while (*s) { *s = (char) tolower((unsigned char) *s); s++; } }

int main() {
    const char *scrambled[NUM_Q] = {"ATED", "LISTEN", "NIGHT", "MELON", "STONE"};
    const char *hints[NUM_Q] = {"opposite of alive", "to hear", "opposite of day", "a fruit", "a small rock"};
    const char *answers[NUM_Q] = {"dead", "silent", "thing", "lemon", "notes"};
    char guess[50];
    int score = 0, i;

    printf("=== Anagram Challenge ===\nUnscramble letters to form a word matching the hint.\n");

    for (i = 0; i < NUM_Q; i++) {
        printf("\nLetters: %s (hint: %s)\n> ", scrambled[i], hints[i]);
        scanf("%49s", guess);
        toLower(guess);

        if (strcmp(guess, answers[i]) == 0) { printf("Correct!\n"); score++; }
        else printf("One valid answer was: %s\n", answers[i]);
    }

    printf("\nFinal score: %d/%d\n", score, NUM_Q);
    return 0;
}
