#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int hand[5], i, rerollCount, idx, counts[15] = {0};

    srand((unsigned int) time(NULL));
    printf("=== Video Poker (5-card draw, simplified) ===\n");

    for (i = 0; i < 5; i++) hand[i] = 2 + rand() % 13;

    printf("Your hand: ");
    for (i = 0; i < 5; i++) printf("%d ", hand[i]);
    printf("\n");

    printf("How many cards to discard and redraw (0-5)? ");
    if (scanf("%d", &rerollCount) == 1 && rerollCount > 0 && rerollCount <= 5) {
        printf("Enter %d card positions to redraw (1-5): ", rerollCount);
        for (i = 0; i < rerollCount; i++) {
            if (scanf("%d", &idx) == 1 && idx >= 1 && idx <= 5) hand[idx - 1] = 2 + rand() % 13;
        }
        printf("New hand: ");
        for (i = 0; i < 5; i++) printf("%d ", hand[i]);
        printf("\n");
    }

    for (i = 0; i < 5; i++) counts[hand[i]]++;

    {
        int pairs = 0, threeKind = 0, fourKind = 0;
        for (i = 2; i <= 14; i++) {
            if (counts[i] == 2) pairs++;
            if (counts[i] == 3) threeKind = 1;
            if (counts[i] == 4) fourKind = 1;
        }

        if (fourKind) printf("\nFour of a Kind! Big win!\n");
        else if (threeKind && pairs == 1) printf("\nFull House! Great win!\n");
        else if (threeKind) printf("\nThree of a Kind! You win!\n");
        else if (pairs >= 2) printf("\nTwo Pair! You win!\n");
        else if (pairs == 1) printf("\nOne Pair. Small win.\n");
        else printf("\nNo winning combination.\n");
    }

    return 0;
}
