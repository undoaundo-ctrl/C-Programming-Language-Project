#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numPlayers, i, roll, highest = -1, winner = -1;

    srand((unsigned int) time(NULL));
    printf("=== Dice Roller Multiplayer ===\nHow many players? ");
    if (scanf("%d", &numPlayers) != 1 || numPlayers < 2 || numPlayers > 10) return 1;

    for (i = 1; i <= numPlayers; i++) {
        roll = 1 + rand() % 6;
        printf("Player %d rolled: %d\n", i, roll);
        if (roll > highest) { highest = roll; winner = i; }
    }

    printf("\nPlayer %d wins with a roll of %d!\n", winner, highest);
    return 0;
}
