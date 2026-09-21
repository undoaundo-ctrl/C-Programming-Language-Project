#include <stdio.h>

#define SIZE 5

int main() {
    int grid[SIZE][SIZE] = {{0}};
    int row = 0, col = 0, dir = 0;
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    int num;

    printf("=== Number Spiral ===\nFilling a %dx%d grid in spiral order...\n", SIZE, SIZE);

    for (num = 1; num <= SIZE * SIZE; num++) {
        grid[row][col] = num;
        {
            int nr = row + dr[dir], nc = col + dc[dir];
            if (nr < 0 || nr >= SIZE || nc < 0 || nc >= SIZE || grid[nr][nc] != 0) {
                dir = (dir + 1) % 4;
                nr = row + dr[dir];
                nc = col + dc[dir];
            }
            row = nr; col = nc;
        }
    }

    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) printf("%3d ", grid[row][col]);
        printf("\n");
    }

    printf("\nGuess the number at the center of the spiral: ");
    {
        int guess;
        scanf("%d", &guess);
        if (guess == grid[SIZE/2][SIZE/2]) printf("Correct! The center is %d\n", grid[SIZE/2][SIZE/2]);
        else printf("Wrong! The center is %d\n", grid[SIZE/2][SIZE/2]);
    }

    return 0;
}
