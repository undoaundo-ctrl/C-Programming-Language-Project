#include <stdio.h>

int main() {
    int pos[4] = {0, 0, 0, 0};
    int moves = 0;

    printf("=== River Crossing Puzzle ===\n");
    printf("Move the farmer, fox, goose, and grain across. Fox eats goose, goose eats grain if left alone!\n");
    printf("Enter item to move with farmer: 0=none(just farmer), 1=fox, 2=goose, 3=grain\n");

    while (!(pos[0] == 1 && pos[1] == 1 && pos[2] == 1 && pos[3] == 1)) {
        int item;
        printf("\nFarmer: %s | Fox: %s | Goose: %s | Grain: %s\n",
               pos[3] ? "far side" : "start side",
               pos[0] ? "far side" : "start side",
               pos[1] ? "far side" : "start side",
               pos[2] ? "far side" : "start side");

        printf("Move item (0=none,1=fox,2=goose,3=grain): ");
        if (scanf("%d", &item) != 1) break;

        if (item < 0 || item > 3) { printf("Invalid.\n"); continue; }
        if (item != 0 && pos[item - 1] != pos[3]) { printf("That item isn't with the farmer.\n"); continue; }

        pos[3] = !pos[3];
        if (item != 0) pos[item - 1] = pos[3];
        moves++;

        if (pos[0] == pos[1] && pos[0] != pos[3]) { printf("\nThe fox ate the goose! Game over.\n"); return 0; }
        if (pos[1] == pos[2] && pos[1] != pos[3]) { printf("\nThe goose ate the grain! Game over.\n"); return 0; }
    }

    printf("\nEveryone crossed safely in %d moves! You win!\n", moves);
    return 0;
}
