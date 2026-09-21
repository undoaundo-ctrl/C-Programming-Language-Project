#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int hand[7], i, j, sortedTmp;

    srand((unsigned int) time(NULL));
    for (i = 0; i < 7; i++) hand[i] = 1 + rand() % 13;

    for (i = 0; i < 7; i++)
        for (j = i + 1; j < 7; j++)
            if (hand[j] < hand[i]) { sortedTmp = hand[i]; hand[i] = hand[j]; hand[j] = sortedTmp; }

    printf("=== Simple Rummy ===\nYour sorted hand: ");
    for (i = 0; i < 7; i++) printf("%d ", hand[i]);
    printf("\n");

    {
        int runLen = 1, bestRun = 1;
        for (i = 1; i < 7; i++) {
            if (hand[i] == hand[i - 1] + 1) { runLen++; if (runLen > bestRun) bestRun = runLen; }
            else runLen = 1;
        }
        printf("\nLongest run found: %d cards\n", bestRun);
        if (bestRun >= 3) printf("You have a valid run! Good hand!\n");
        else printf("No run of 3+ yet, keep drawing.\n");
    }

    return 0;
}
