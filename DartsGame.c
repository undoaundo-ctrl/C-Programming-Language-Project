#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int throws = 3, i, score, totalScore = 0;

    srand((unsigned int) time(NULL));
    printf("=== Darts Game ===\nYou get %d throws. Scoring is simulated by aim precision.\n", throws);

    for (i = 1; i <= throws; i++) {
        int aim;
        printf("\nThrow %d - Aim for the bullseye (enter 1-10, 10=center): ", i);
        if (scanf("%d", &aim) != 1) continue;
        if (aim < 1) aim = 1;
        if (aim > 10) aim = 10;

        score = aim * (5 + rand() % 6) / 5;
        printf("You scored %d points!\n", score);
        totalScore += score;
    }

    printf("\nTotal score: %d\n", totalScore);
    return 0;
}
