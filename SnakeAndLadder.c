#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getSnakeOrLadder(int pos) {
    switch (pos) {
        case 4: return 25;
        case 13: return 46;
        case 33: return 49;
        case 42: return 63;
        case 50: return 69;
        case 62: return 19;
        case 64: return 60;
        case 87: return 24;
        case 93: return 73;
        case 95: return 75;
        case 99: return 78;
        default: return pos;
    }
}

int main() {
    int playerPos = 0, computerPos = 0, roll, turn = 0;

    srand((unsigned int) time(NULL));
    printf("=== Snake and Ladder ===\nFirst to reach 100 wins! Press enter to roll.\n");

    while (playerPos < 100 && computerPos < 100) {
        if (turn == 0) {
            printf("\nYour turn. Press enter to roll...");
            getchar();
            roll = 1 + rand() % 6;
            printf("You rolled: %d\n", roll);
            playerPos += roll;
            if (playerPos > 100) playerPos -= roll;
            else playerPos = getSnakeOrLadder(playerPos);
            printf("Your position: %d\n", playerPos);
        } else {
            roll = 1 + rand() % 6;
            printf("\nComputer rolled: %d\n", roll);
            computerPos += roll;
            if (computerPos > 100) computerPos -= roll;
            else computerPos = getSnakeOrLadder(computerPos);
            printf("Computer position: %d\n", computerPos);
        }
        turn = 1 - turn;
    }

    if (playerPos >= 100) printf("\nYou win!\n");
    else printf("\nComputer wins!\n");

    return 0;
}
