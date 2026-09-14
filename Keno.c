#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PICKS 5
#define DRAWN 10
#define MAX_NUM 40

int main() {
    int picks[PICKS], drawn[DRAWN], i, j, matches = 0;
    int used[MAX_NUM + 1] = {0};

    srand((unsigned int) time(NULL));
    printf("=== Keno ===\nPick %d numbers between 1 and %d.\n", PICKS, MAX_NUM);

    for (i = 0; i < PICKS; i++) {
        printf("Pick %d: ", i + 1);
        if (scanf("%d", &picks[i]) != 1 || picks[i] < 1 || picks[i] > MAX_NUM) { printf("Invalid.\n"); i--; continue; }
    }

    for (i = 0; i < DRAWN; i++) {
        int num;
        do { num = 1 + rand() % MAX_NUM; } while (used[num]);
        used[num] = 1;
        drawn[i] = num;
    }

    printf("\nDrawn numbers: ");
    for (i = 0; i < DRAWN; i++) printf("%d ", drawn[i]);
    printf("\n");

    for (i = 0; i < PICKS; i++)
        for (j = 0; j < DRAWN; j++)
            if (picks[i] == drawn[j]) matches++;

    printf("\nYou matched %d out of %d numbers!\n", matches, PICKS);
    if (matches >= 3) printf("You win a prize!\n");
    else printf("Better luck next time!\n");

    return 0;
}
