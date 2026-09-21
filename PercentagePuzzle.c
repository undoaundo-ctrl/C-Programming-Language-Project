#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int whole, percent, guess, score = 0, rounds = 5, i;

    srand((unsigned int) time(NULL));
    printf("=== Percentage Puzzle ===\nCalculate the percentage of the number.\n");

    for (i = 1; i <= rounds; i++) {
        whole = 20 + rand() % 180;
        percent = 5 * (1 + rand() % 19);
        printf("\nWhat is %d%% of %d? ", percent, whole);
        if (scanf("%d", &guess) != 1) continue;

        {
            int correctAns = (whole * percent) / 100;
            if (guess == correctAns) { printf("Correct!\n"); score++; }
            else printf("Wrong! Answer: %d\n", correctAns);
        }
    }

    printf("\nFinal score: %d/%d\n", score, rounds);
    return 0;
}
