#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int scoreDice(int dice[5]) {
    int counts[7] = {0}, i, score = 0;
    for (i = 0; i < 5; i++) counts[dice[i]]++;

    for (i = 1; i <= 6; i++) {
        if (counts[i] >= 3) {
            score += (i == 1) ? 1000 : i * 100;
            counts[i] -= 3;
        }
    }
    score += counts[1] * 100;
    score += counts[5] * 50;

    return score;
}

int main() {
    int dice[5], i, totalScore = 0, roundScore;
    char again;

    srand((unsigned int) time(NULL));
    printf("=== Farkle (simplified single-turn scoring) ===\n");

    do {
        for (i = 0; i < 5; i++) dice[i] = 1 + rand() % 6;

        printf("\nRoll: ");
        for (i = 0; i < 5; i++) printf("%d ", dice[i]);
        printf("\n");

        roundScore = scoreDice(dice);
        printf("Score for this roll: %d\n", roundScore);
        totalScore += roundScore;

        if (roundScore == 0) printf("Farkle! No scoring dice.\n");

        printf("Roll again? (y/n): ");
        scanf(" %c", &again);
    } while (again == 'y' || again == 'Y');

    printf("\nTotal score: %d\n", totalScore);
    return 0;
}
