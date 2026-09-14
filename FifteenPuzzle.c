#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

int grid[SIZE][SIZE];
int blankRow, blankCol;

void printGrid() {
    int i, j;
    printf("\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0) printf("   .");
            else printf("%4d", grid[i][j]);
        }
        printf("\n");
    }
}

int isSolved() {
    int expected = 1, i, j;
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++) {
            if (i == SIZE - 1 && j == SIZE - 1) return grid[i][j] == 0;
            if (grid[i][j] != expected++) return 0;
        }
    return 1;
}

int main() {
    int i, j, k = 1;
    char dir;

    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            grid[i][j] = (k < 16) ? k++ : 0;
    blankRow = SIZE - 1;
    blankCol = SIZE - 1;

    srand((unsigned int) time(NULL));
    for (i = 0; i < 50; i++) {
        int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};
        int d = rand() % 4;
        int nr = blankRow + dr[d], nc = blankCol + dc[d];
        if (nr >= 0 && nr < SIZE && nc >= 0 && nc < SIZE) {
            grid[blankRow][blankCol] = grid[nr][nc];
            grid[nr][nc] = 0;
            blankRow = nr; blankCol = nc;
        }
    }

    printf("=== 15 Puzzle ===\nArrange tiles 1-15 in order. Controls: w/a/s/d to slide into the blank, q to quit\n");

    while (!isSolved()) {
        printGrid();
        printf("\nMove: ");
        if (scanf(" %c", &dir) != 1) break;
        if (dir == 'q') { printf("Bye!\n"); return 0; }

        {
            int nr = blankRow, nc = blankCol;
            if (dir == 'w') nr++;
            else if (dir == 's') nr--;
            else if (dir == 'a') nc++;
            else if (dir == 'd') nc--;
            else { printf("Invalid.\n"); continue; }

            if (nr < 0 || nr >= SIZE || nc < 0 || nc >= SIZE) { printf("Can't move that way.\n"); continue; }

            grid[blankRow][blankCol] = grid[nr][nc];
            grid[nr][nc] = 0;
            blankRow = nr; blankCol = nc;
        }
    }

    printGrid();
    printf("\nSolved! Great job!\n");
    return 0;
}
