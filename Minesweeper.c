#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 6
#define MINES 5

int mines[SIZE][SIZE];
int revealed[SIZE][SIZE];

void placeMines() {
    int placed = 0, r, c;
    while (placed < MINES) {
        r = rand() % SIZE;
        c = rand() % SIZE;
        if (!mines[r][c]) {
            mines[r][c] = 1;
            placed++;
        }
    }
}

int countAdjacent(int row, int col) {
    int count = 0, dr, dc, r, c;
    for (dr = -1; dr <= 1; dr++) {
        for (dc = -1; dc <= 1; dc++) {
            r = row + dr;
            c = col + dc;
            if (r >= 0 && r < SIZE && c >= 0 && c < SIZE && mines[r][c]) count++;
        }
    }
    return count;
}

void printBoard(int showMines) {
    int i, j;
    printf("\n   ");
    for (j = 0; j < SIZE; j++) printf("%d ", j);
    printf("\n");

    for (i = 0; i < SIZE; i++) {
        printf("%2d ", i);
        for (j = 0; j < SIZE; j++) {
            if (showMines && mines[i][j]) {
                printf("* ");
            } else if (revealed[i][j]) {
                printf("%d ", countAdjacent(i, j));
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    int row, col, revealedCount = 0, totalSafe = SIZE * SIZE - MINES;

    srand((unsigned int) time(NULL));
    placeMines();

    printf("=== Minesweeper ===\n");
    printf("Board is %dx%d with %d mines. Reveal all safe cells to win.\n", SIZE, SIZE, MINES);

    while (revealedCount < totalSafe) {
        printBoard(0);
        printf("Enter row and column to reveal: ");

        if (scanf("%d %d", &row, &col) != 2) {
            printf("Invalid input.\n");
            break;
        }

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
            printf("Out of bounds, try again.\n");
            continue;
        }

        if (revealed[row][col]) {
            printf("Already revealed, try another cell.\n");
            continue;
        }

        if (mines[row][col]) {
            printBoard(1);
            printf("\nBOOM! You hit a mine. Game over.\n");
            return 0;
        }

        revealed[row][col] = 1;
        revealedCount++;
    }

    printBoard(1);
    printf("\nCongratulations! You cleared the board!\n");

    return 0;
}
