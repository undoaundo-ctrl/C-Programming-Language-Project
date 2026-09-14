#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int start, step, seq[5], i, guess, score = 0, rounds = 5, r;

    srand((unsigned int) time(NULL));
    printf("=== Arithmetic Sequence Puzzle ===\nFigure out the next number in each sequence.\n");

    for (r = 1; r <= rounds; r++) {
        start = 1 + rand() % 10;
        step = 1 + rand() % 5;
        for (i = 0; i < 5; i++) seq[i] = start + i * step;

        printf("\nRound %d: ", r);
        for (i = 0; i < 4; i++) printf("%d, ", seq[i]);
        printf("? ");

        if (scanf("%d", &guess) != 1) continue;

        if (guess == seq[4]) { printf("Correct!\n"); score++; }
        else printf("Wrong! The answer was %d\n", seq[4]);
    }

    printf("\nFinal score: %d/%d\n", score, rounds);
    return 0;
}
