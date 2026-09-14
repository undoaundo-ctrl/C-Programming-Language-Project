#include <stdio.h>

#define SIZE 5
int visited[SIZE][SIZE];

int main() {
    int row, col, moves = 1, dr, dc;

    for (row = 0; row < SIZE; row++) for (col = 0; col < SIZE; col++) visited[row][col] = 0;

    printf("=== Knight's Tour Challenge ===\nMove your knight to visit as many new squares as possible.\n");
    printf("Starting position (row col, 0-4): ");
    if (scanf("%d %d", &row, &col) != 2 || row < 0 || row >= SIZE || col < 0 || col >= SIZE) return 1;

    visited[row][col] = 1;

    while (1) {
        int i, j;
        printf("\n");
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                if (i == row && j == col) printf("K ");
                else printf("%c ", visited[i][j] ? '#' : '.');
            }
            printf("\n");
        }
        printf("Squares visited: %d/%d\n", moves, SIZE * SIZE);
        printf("Move to (row col, or -1 -1 to stop): ");
        if (scanf("%d %d", &dr, &dc) != 2) break;
        if (dr == -1) break;

        if (dr < 0 || dr >= SIZE || dc < 0 || dc >= SIZE) { printf("Out of bounds.\n"); continue; }

        {
            int rd = dr - row, cd = dc - col;
            if (rd < 0) rd = -rd;
            if (cd < 0) cd = -cd;
            if (!((rd == 1 && cd == 2) || (rd == 2 && cd == 1))) { printf("Not a valid knight move.\n"); continue; }
        }
        if (visited[dr][dc]) { printf("Already visited that square.\n"); continue; }

        row = dr; col = dc;
        visited[row][col] = 1;
        moves++;
    }

    printf("\nFinal score: %d squares visited out of %d!\n", moves, SIZE * SIZE);
    return 0;
}
