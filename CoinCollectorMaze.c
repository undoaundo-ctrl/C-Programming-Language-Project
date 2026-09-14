#include <stdio.h>

#define SIZE 6

char grid[SIZE][SIZE + 1] = {
    "P.C..C",
    ".#.#..",
    "C..#.C",
    ".#....",
    "..#.#.",
    "C....C"
};

int main() {
    int px = 0, py = 0, i, j, coins = 0, totalCoins = 0, moves = 20;
    char move;

    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++) {
            if (grid[i][j] == 'P') { py = i; px = j; }
            if (grid[i][j] == 'C') totalCoins++;
        }

    printf("=== Coin Collector Maze ===\nCollect all %d coins in %d moves. w/a/s/d, q to quit\n", totalCoins, moves);

    while (moves > 0 && coins < totalCoins) {
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                if (i == py && j == px) printf("@");
                else printf("%c", grid[i][j]);
            }
            printf("\n");
        }
        printf("Coins: %d/%d | Moves left: %d\nMove: ", coins, totalCoins, moves);
        if (scanf(" %c", &move) != 1) break;
        if (move == 'q') { printf("Bye!\n"); return 0; }

        {
            int nx = px, ny = py;
            if (move == 'w') ny--;
            else if (move == 's') ny++;
            else if (move == 'a') nx--;
            else if (move == 'd') nx++;
            else { printf("Invalid.\n"); continue; }

            if (nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE || grid[ny][nx] == '#') {
                printf("Can't move there.\n");
                continue;
            }
            px = nx; py = ny;
            moves--;
            if (grid[py][px] == 'C') { grid[py][px] = '.'; coins++; printf("Collected a coin!\n"); }
        }
    }

    if (coins == totalCoins) printf("\nYou collected all coins! You win!\n");
    else printf("\nOut of moves! You collected %d/%d coins.\n", coins, totalCoins);

    return 0;
}
