#include <stdio.h>

int main() {
    int grid[3][3], i, j, target, valid = 1;

    printf("=== Magic Square Builder ===\nFill a 3x3 grid with numbers 1-9 (each used once) so every row, column, and diagonal sums the same.\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Enter value for cell [%d][%d]: ", i, j);
            if (scanf("%d", &grid[i][j]) != 1) return 1;
        }
    }

    target = grid[0][0] + grid[0][1] + grid[0][2];

    for (i = 0; i < 3; i++) {
        int rowSum = 0, colSum = 0;
        for (j = 0; j < 3; j++) { rowSum += grid[i][j]; colSum += grid[j][i]; }
        if (rowSum != target || colSum != target) valid = 0;
    }

    {
        int diag1 = grid[0][0] + grid[1][1] + grid[2][2];
        int diag2 = grid[0][2] + grid[1][1] + grid[2][0];
        if (diag1 != target || diag2 != target) valid = 0;
    }

    if (valid) printf("\nCongratulations! That's a valid magic square (sum = %d)!\n", target);
    else printf("\nNot a magic square. Try again!\n");

    return 0;
}
