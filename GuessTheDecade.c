#include <stdio.h>

#define NUM_Q 4

int main() {
    const char *events[NUM_Q] = {
        "The first iPhone was released",
        "The Internet became widely available to the public",
        "Disco music was at its peak popularity",
        "The first color television broadcasts began"
    };
    int decades[NUM_Q] = {2000, 1990, 1970, 1950};
    int guess, score = 0, i;

    printf("=== Guess the Decade ===\nWhich decade did this happen in? (enter as e.g. 1990)\n");

    for (i = 0; i < NUM_Q; i++) {
        printf("\n%s. > ", events[i]);
        if (scanf("%d", &guess) != 1) continue;

        if (guess == decades[i]) { printf("Correct!\n"); score++; }
        else printf("Answer: the %ds\n", decades[i]);
    }

    printf("\nFinal score: %d/%d\n", score, NUM_Q);
    return 0;
}
