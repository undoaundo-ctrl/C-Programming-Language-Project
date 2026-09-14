#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_Q 5

void toLower(char *s) { while (*s) { *s = (char) tolower((unsigned char) *s); s++; } }

int main() {
    const char *questions[NUM_Q] = {
        "What ocean liner sank in 1912, subject of a famous film?",
        "What is the name of the wizarding school in a famous book/film series about a boy wizard?",
        "In a famous space opera, what is the name of the villain who says 'I am your father'?",
        "What 1990s film features dinosaurs cloned from amber-preserved DNA?",
        "What animated film features a lion cub named Simba?"
    };
    const char *answers[NUM_Q] = {"titanic", "hogwarts", "vader", "jurassic park", "the lion king"};
    char guess[100];
    int score = 0, i;

    printf("=== Movie Trivia Quiz ===\n");

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
