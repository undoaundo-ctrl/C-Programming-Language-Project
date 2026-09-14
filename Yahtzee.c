#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int dice[5], counts[7] = {0}, i, rerollCount, idx;

    srand((unsigned int) time(NULL));
    printf("=== Yahtzee (single roll challenge) ===\n");

    for (i = 0; i < 5; i++) dice[i] = 1 + rand() % 6;

    printf("Your roll: ");
    for (i = 0; i < 5; i++) printf("%d ", dice[i]);
    printf("\n");

    printf("Reroll how many dice (0-5)? ");
    if (scanf("%d", &rerollCount) == 1 && rerollCount > 0 && rerollCount <= 5) {
        printf("Enter %d dice positions to reroll (1-5): ", rerollCount);
        for (i = 0; i < rerollCount; i++) {
            if (scanf("%d", &idx) == 1 && idx >= 1 && idx <= 5) {
                dice[idx - 1] = 1 + rand() % 6;
            }
        }
        printf("New roll: ");
        for (i = 0; i < 5; i++) printf("%d ", dice[i]);
        printf("\n");
    }

    for (i = 0; i < 5; i++) counts[dice[i]]++;

    {
        int isYahtzee = 0, isFourKind = 0, isFullHouse = 0, has3 = 0, has2 = 0;
        for (i = 1; i <= 6; i++) {
            if (counts[i] == 5) isYahtzee = 1;
            if (counts[i] == 4) isFourKind = 1;
            if (counts[i] == 3) has3 = 1;
            if (counts[i] == 2) has2 = 1;
        }
        isFullHouse = has3 && has2;

        if (isYahtzee) printf("\nYAHTZEE! Five of a kind!\n");
        else if (isFourKind) printf("\nFour of a kind!\n");
        else if (isFullHouse) printf("\nFull House!\n");
        else printf("\nNo special combo this time.\n");
    }

    return 0;
}
