#include <stdio.h>

int grid[4][4] = {
    {1, 0, 0, 4},
    {0, 4, 1, 0},
    {0, 1, 4, 0},
    {4, 0, 0, 1}
};

void printGrid() {
    int i, j;
    printf("\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (grid[i][j] == 0) printf(". ");
            else printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int isValid(int row, int col, int num) {
    int i, j, boxRow, boxCol;
    for (i = 0; i < 4; i++) {
        if (grid[row][i] == num || grid[i][col] == num) return 0;
    }
    boxRow = (row / 2) * 2;
    boxCol = (col / 2) * 2;
    for (i = boxRow; i < boxRow + 2; i++)
        for (j = boxCol; j < boxCol + 2; j++)
            if (grid[i][j] == num) return 0;
    return 1;
}

int isFull() {
    int i, j;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            if (grid[i][j] == 0) return 0;
    return 1;
}

int main() {
    int row, col, num;

    printf("=== Mini Sudoku (4x4) ===\nFill with digits 1-4, no repeats in row/col/box.\n");

    while (!isFull()) {
        printGrid();
        printf("Enter row(0-3) col(0-3) number(1-4): ");
        if (scanf("%d %d %d", &row, &col, &num) != 3) break;

        if (row < 0 || row > 3 || col < 0 || col > 3 || num < 1 || num > 4) {
            printf("Invalid input.\n");
            continue;
        }
        if (grid[row][col] != 0) { printf("Cell already filled.\n"); continue; }
        if (!isValid(row, col, num)) { printf("Invalid move, breaks Sudoku rule.\n"); continue; }

        grid[row][col] = num;
    }

    printGrid();
    printf("\nSolved! Great job!\n");
    return 0;
}
