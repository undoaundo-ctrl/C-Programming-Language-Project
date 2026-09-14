#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int current, next, guess, score = 0, rounds = 10, i;

    srand((unsigned int) time(NULL));
    current = 1 + rand() % 13;

    printf("=== High-Low Card ===\nGuess if the next card is higher (1) or lower (0).\n");

    for (i = 1; i <= rounds; i++) {
        printf("\nCurrent card: %d\n", current);
        printf("Next card higher(1) or lower(0)? ");
        if (scanf("%d", &guess) != 1) break;

        next = 1 + rand() % 13;
        printf("Next card was: %d\n", next);

        if ((next > current && guess == 1) || (next < current && guess == 0)) {
            printf("Correct!\n");
            score++;
        } else if (next == current) {
            printf("It was a tie card, no points.\n");
        } else {
            printf("Wrong!\n");
        }
        current = next;
    }

    printf("\nFinal score: %d/%d\n", score, rounds);
    return 0;
}
