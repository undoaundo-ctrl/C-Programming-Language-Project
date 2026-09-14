#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRACK_LEN 20

int main() {
    int posA = 0, posB = 0, roll;
    int i;

    srand((unsigned int) time(NULL));
    printf("=== ASCII Dice Race ===\nFirst racer to reach the end wins!\n");

    while (posA < TRACK_LEN && posB < TRACK_LEN) {
        roll = 1 + rand() % 6;
        posA += roll;
        if (posA > TRACK_LEN) posA = TRACK_LEN;
        printf("\nRacer A rolled %d\n", roll);

        roll = 1 + rand() % 6;
        posB += roll;
        if (posB > TRACK_LEN) posB = TRACK_LEN;
        printf("Racer B rolled %d\n", roll);

        printf("A: ");
        for (i = 0; i < TRACK_LEN; i++) printf(i < posA ? "=" : ".");
        printf(">\n");

        printf("B: ");
        for (i = 0; i < TRACK_LEN; i++) printf(i < posB ? "=" : ".");
        printf(">\n");
    }

    if (posA >= TRACK_LEN && posB >= TRACK_LEN) printf("\nIt's a tie!\n");
    else if (posA >= TRACK_LEN) printf("\nRacer A wins!\n");
    else printf("\nRacer B wins!\n");

    return 0;
}
