#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 6
char board[SIZE][SIZE];

void initBoard() {
    int i, j;
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++) {
            if ((i + j) % 2 == 1 && i < 2) board[i][j] = 'o';
            else if ((i + j) % 2 == 1 && i >= SIZE - 2) board[i][j] = 'x';
            else board[i][j] = '.';
        }
}

void printBoard() {
    int i, j;
    printf("\n   ");
    for (j = 0; j < SIZE; j++) printf("%d ", j);
    printf("\n");
    for (i = 0; i < SIZE; i++) {
        printf("%2d ", i);
        for (j = 0; j < SIZE; j++) printf("%c ", board[i][j]);
        printf("\n");
    }
}

int countPieces(char p) {
    int i, j, count = 0;
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            if (board[i][j] == p) count++;
    return count;
}

void computerMove() {
    int i, j, dj;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == 'o') {
                for (dj = -1; dj <= 1; dj += 2) {
                    if (i + 1 < SIZE && j + dj >= 0 && j + dj < SIZE && board[i + 1][j + dj] == '.') {
                        board[i][j] = '.';
                        board[i + 1][j + dj] = 'o';
                        return;
                    }
                }
            }
        }
    }
}

int main() {
    int r1, c1, r2, c2;

    srand((unsigned int) time(NULL));
    initBoard();
    printf("=== Checkers (simplified, no jumps, first to lose all pieces loses) ===\n");
    printf("You are x (moves up), computer is o (moves down).\n");

    while (countPieces('x') > 0 && countPieces('o') > 0) {
        printBoard();
        printf("Move (from_row from_col to_row to_col): ");
        if (scanf("%d %d %d %d", &r1, &c1, &r2, &c2) != 4) break;

        if (r1 < 0 || r1 >= SIZE || c1 < 0 || c1 >= SIZE || r2 < 0 || r2 >= SIZE || c2 < 0 || c2 >= SIZE) {
            printf("Out of bounds.\n"); continue;
        }
        if (board[r1][c1] != 'x') { printf("No piece of yours there.\n"); continue; }
        if (board[r2][c2] != '.') { printf("Destination occupied.\n"); continue; }
        if (r2 != r1 - 1 || (c2 != c1 - 1 && c2 != c1 + 1)) { printf("Invalid move for a piece moving up diagonally.\n"); continue; }

        board[r1][c1] = '.';
        board[r2][c2] = 'x';

        computerMove();
    }

    printBoard();
    if (countPieces('o') == 0) printf("\nYou win!\n");
    else printf("\nComputer wins (or ran out of moves)!\n");

    return 0;
}
