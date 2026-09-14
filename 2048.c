#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 4

int grid[SIZE][SIZE];

void addRandomTile() {
    int emptyRow[SIZE * SIZE], emptyCol[SIZE * SIZE], count = 0, i, j, pick;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0) {
                emptyRow[count] = i;
                emptyCol[count] = j;
                count++;
            }
        }
    }
    if (count == 0) return;
    pick = rand() % count;
    grid[emptyRow[pick]][emptyCol[pick]] = (rand() % 10 == 0) ? 4 : 2;
}

void printGrid() {
    int i, j;
    printf("\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0) printf(" .   ");
            else printf("%4d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int slideAndMergeLine(int line[SIZE]) {
    int result[SIZE] = {0, 0, 0, 0};
    int pos = 0, i, moved = 0;
    int temp[SIZE];
    int tempCount = 0;

    for (i = 0; i < SIZE; i++) {
        if (line[i] != 0) temp[tempCount++] = line[i];
    }

    for (i = 0; i < tempCount; i++) {
        if (i < tempCount - 1 && temp[i] == temp[i + 1]) {
            result[pos++] = temp[i] * 2;
            i++;
        } else {
            result[pos++] = temp[i];
        }
    }

    for (i = 0; i < SIZE; i++) {
        if (line[i] != result[i]) moved = 1;
        line[i] = result[i];
    }

    return moved;
}

void reverseLine(int line[SIZE]) {
    int i, tmp;
    for (i = 0; i < SIZE / 2; i++) {
        tmp = line[i];
        line[i] = line[SIZE - 1 - i];
        line[SIZE - 1 - i] = tmp;
    }
}

int moveLeft() {
    int i, moved = 0;
    for (i = 0; i < SIZE; i++) {
        if (slideAndMergeLine(grid[i])) moved = 1;
    }
    return moved;
}

int moveRight() {
    int i, moved = 0;
    for (i = 0; i < SIZE; i++) {
        reverseLine(grid[i]);
        if (slideAndMergeLine(grid[i])) moved = 1;
        reverseLine(grid[i]);
    }
    return moved;
}

int moveUp() {
    int i, j, col[SIZE], moved = 0;
    for (j = 0; j < SIZE; j++) {
        for (i = 0; i < SIZE; i++) col[i] = grid[i][j];
        if (slideAndMergeLine(col)) moved = 1;
        for (i = 0; i < SIZE; i++) grid[i][j] = col[i];
    }
    return moved;
}

int moveDown() {
    int i, j, col[SIZE], moved = 0;
    for (j = 0; j < SIZE; j++) {
        for (i = 0; i < SIZE; i++) col[i] = grid[SIZE - 1 - i][j];
        if (slideAndMergeLine(col)) moved = 1;
        for (i = 0; i < SIZE; i++) grid[SIZE - 1 - i][j] = col[i];
    }
    return moved;
}

int hasMoves() {
    int i, j;
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            if (grid[i][j] == 0) return 1;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE - 1; j++) {
            if (grid[i][j] == grid[i][j + 1]) return 1;
            if (grid[j][i] == grid[j + 1][i]) return 1;
        }
    }
    return 0;
}

int hasWon() {
    int i, j;
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            if (grid[i][j] >= 2048) return 1;
    return 0;
}

int main() {
    char move;
    int moved;

    srand((unsigned int) time(NULL));
    memset(grid, 0, sizeof(grid));
    addRandomTile();
    addRandomTile();

    printf("=== 2048 ===\n");
    printf("Controls: w = up, s = down, a = left, d = right, q = quit\n");

    while (1) {
        printGrid();

        if (hasWon()) {
            printf("You reached 2048! You win!\n");
            break;
        }

        if (!hasMoves()) {
            printf("No more moves left. Game over!\n");
            break;
        }

        printf("Your move: ");
        if (scanf(" %c", &move) != 1) break;

        moved = 0;
        switch (move) {
            case 'w': moved = moveUp(); break;
            case 's': moved = moveDown(); break;
            case 'a': moved = moveLeft(); break;
            case 'd': moved = moveRight(); break;
            case 'q': printf("Thanks for playing!\n"); return 0;
            default: printf("Invalid move.\n"); continue;
        }

        if (moved) {
            addRandomTile();
        } else {
            printf("That move didn't change the board, try another direction.\n");
        }
    }

    return 0;
}
