#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

int main() {
    int treasureX, treasureY, guessX, guessY, tries = 0, maxTries = 10;
    int dx, dy;

    srand((unsigned int) time(NULL));
    treasureX = rand() % SIZE;
    treasureY = rand() % SIZE;

    printf("=== Treasure Hunt ===\nFind the treasure on an %dx%d grid. You have %d tries.\n", SIZE, SIZE, maxTries);
    printf("Hints: hot/cold based on distance.\n");

    while (tries < maxTries) {
        tries++;
        printf("\nTry %d - Enter row and column: ", tries);
        if (scanf("%d %d", &guessX, &guessY) != 2) break;

        if (guessX == treasureX && guessY == treasureY) {
            printf("\nYou found the treasure in %d tries!\n", tries);
            return 0;
        }

        dx = guessX - treasureX; if (dx < 0) dx = -dx;
        dy = guessY - treasureY; if (dy < 0) dy = -dy;

        if (dx + dy <= 1) printf("Burning hot!\n");
        else if (dx + dy <= 3) printf("Hot!\n");
        else if (dx + dy <= 5) printf("Warm.\n");
        else printf("Cold.\n");
    }

    printf("\nOut of tries! The treasure was at (%d, %d).\n", treasureX, treasureY);
    return 0;
}
