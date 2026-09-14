#include <stdio.h>

#define SIZE 4
char board[SIZE][SIZE];

void printBoard() {
    int i, j;
    printf("\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) printf(" %c", board[i][j]);
        printf("\n");
    }
}

int checkWin(char p) {
    int i, j, k, win;

    for (i = 0; i < SIZE; i++) {
        win = 1;
        for (j = 0; j < SIZE; j++) if (board[i][j] != p) win = 0;
        if (win) return 1;
        win = 1;
        for (j = 0; j < SIZE; j++) if (board[j][i] != p) win = 0;
        if (win) return 1;
    }

    win = 1;
    for (k = 0; k < SIZE; k++) if (board[k][k] != p) win = 0;
    if (win) return 1;

    win = 1;
    for (k = 0; k < SIZE; k++) if (board[k][SIZE - 1 - k] != p) win = 0;
    if (win) return 1;

    return 0;
}

int boardFull() {
    int i, j;
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            if (board[i][j] == ' ') return 0;
    return 1;
}

int main() {
    int row, col, turn;
    char player;
    int i, j;

    for (i = 0; i < SIZE; i++) for (j = 0; j < SIZE; j++) board[i][j] = ' ';

    printf("=== Tic-Tac-Toe 4x4 ===\nGet 4 in a row (row, column, or diagonal) to win.\n");

    for (turn = 0; turn < SIZE * SIZE; turn++) {
        player = (turn % 2 == 0) ? 'X' : 'O';
        printBoard();
        printf("Player %c, enter row and column (0-3): ", player);

        if (scanf("%d %d", &row, &col) != 2) break;
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
            printf("Invalid move.\n");
            turn--;
            continue;
        }

        board[row][col] = player;

        if (checkWin(player)) {
            printBoard();
            printf("Player %c wins!\n", player);
            return 0;
        }
    }

    if (boardFull()) { printBoard(); printf("It's a draw!\n"); }
    return 0;
}
