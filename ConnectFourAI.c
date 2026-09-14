#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLS 7

char board[ROWS][COLS];

void initBoard() {
    int i, j;
    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLS; j++)
            board[i][j] = '.';
}

void printBoard() {
    int i, j;
    printf("\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) printf(" %c", board[i][j]);
        printf("\n");
    }
    printf(" 1 2 3 4 5 6 7\n");
}

int dropDisc(int col, char piece) {
    int row;
    if (col < 0 || col >= COLS) return -1;
    for (row = ROWS - 1; row >= 0; row--) {
        if (board[row][col] == '.') { board[row][col] = piece; return row; }
    }
    return -1;
}

int checkWin(int row, int col, char piece) {
    int dr[4] = {0, 1, 1, 1}, dc[4] = {1, 0, 1, -1}, d;
    for (d = 0; d < 4; d++) {
        int count = 1, r, c, k;
        r = row + dr[d]; c = col + dc[d];
        for (k = 0; k < 3 && r >= 0 && r < ROWS && c >= 0 && c < COLS && board[r][c] == piece; k++) { count++; r += dr[d]; c += dc[d]; }
        r = row - dr[d]; c = col - dc[d];
        for (k = 0; k < 3 && r >= 0 && r < ROWS && c >= 0 && c < COLS && board[r][c] == piece; k++) { count++; r -= dr[d]; c -= dc[d]; }
        if (count >= 4) return 1;
    }
    return 0;
}

int computerCol() {
    int col;
    do { col = rand() % COLS; } while (board[0][col] != '.');
    return col;
}

int main() {
    int col, row;

    srand((unsigned int) time(NULL));
    initBoard();
    printf("=== Connect Four vs Computer ===\nYou are X, computer is O.\n");

    while (1) {
        printBoard();
        printf("Your column (1-7): ");
        if (scanf("%d", &col) != 1) break;
        col -= 1;
        row = dropDisc(col, 'X');
        if (row == -1) { printf("Invalid move.\n"); continue; }
        if (checkWin(row, col, 'X')) { printBoard(); printf("You win!\n"); break; }

        col = computerCol();
        row = dropDisc(col, 'O');
        printf("Computer played column %d\n", col + 1);
        if (checkWin(row, col, 'O')) { printBoard(); printf("Computer wins!\n"); break; }
    }

    return 0;
}
