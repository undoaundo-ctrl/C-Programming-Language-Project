#include <stdio.h>

int grid[9][9] = {
    {5,3,0, 0,7,0, 0,0,0},
    {6,0,0, 1,9,5, 0,0,0},
    {0,9,8, 0,0,0, 0,6,0},
    {8,0,0, 0,6,0, 0,0,3},
    {4,0,0, 8,0,3, 0,0,1},
    {7,0,0, 0,2,0, 0,0,6},
    {0,6,0, 0,0,0, 2,8,0},
    {0,0,0, 4,1,9, 0,0,5},
    {0,0,0, 0,8,0, 0,7,9}
};

void printGrid() {
    int i, j;
    printf("\n");
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (grid[i][j] == 0) printf(". ");
            else printf("%d ", grid[i][j]);
            if (j == 2 || j == 5) printf("| ");
        }
        printf("\n");
        if (i == 2 || i == 5) printf("------+-------+------\n");
    }
}

int isValid(int row, int col, int num) {
    int i, j, boxRow, boxCol;
    for (i = 0; i < 9; i++) if (grid[row][i] == num || grid[i][col] == num) return 0;
    boxRow = (row / 3) * 3;
    boxCol = (col / 3) * 3;
    for (i = boxRow; i < boxRow + 3; i++)
        for (j = boxCol; j < boxCol + 3; j++)
            if (grid[i][j] == num) return 0;
    return 1;
}

int isFull() {
    int i, j;
    for (i = 0; i < 9; i++)
        for (j = 0; j < 9; j++)
            if (grid[i][j] == 0) return 0;
    return 1;
}

int main() {
    int row, col, num;

    printf("=== Sudoku (9x9) ===\nFill the grid with digits 1-9, no repeats in row/col/box.\n");

    while (!isFull()) {
        printGrid();
        printf("Enter row(0-8) col(0-8) number(1-9): ");
        if (scanf("%d %d %d", &row, &col, &num) != 3) break;

        if (row < 0 || row > 8 || col < 0 || col > 8 || num < 1 || num > 9) { printf("Invalid input.\n"); continue; }
        if (grid[row][col] != 0) { printf("Cell already filled.\n"); continue; }
        if (!isValid(row, col, num)) { printf("Invalid move.\n"); continue; }

        grid[row][col] = num;
    }

    printGrid();
    printf("\nSolved! Great job!\n");
    return 0;
}
