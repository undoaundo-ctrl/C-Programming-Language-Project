#include <stdio.h>

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
        for (j = 0; j < COLS; j++) {
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
    printf(" 1 2 3 4 5 6 7\n");
}

int dropDisc(int col, char piece) {
    int row;
    if (col < 0 || col >= COLS) return -1;
    for (row = ROWS - 1; row >= 0; row--) {
        if (board[row][col] == '.') {
            board[row][col] = piece;
            return row;
        }
    }
    return -1; /* column full */
}

int checkWin(int row, int col, char piece) {
    int dr[4] = {0, 1, 1, 1};
    int dc[4] = {1, 0, 1, -1};
    int d;

    for (d = 0; d < 4; d++) {
        int count = 1;
        int r, c, k;

        r = row + dr[d];
        c = col + dc[d];
        for (k = 0; k < 3 && r >= 0 && r < ROWS && c >= 0 && c < COLS && board[r][c] == piece; k++) {
            count++;
            r += dr[d];
            c += dc[d];
        }

        r = row - dr[d];
        c = col - dc[d];
        for (k = 0; k < 3 && r >= 0 && r < ROWS && c >= 0 && c < COLS && board[r][c] == piece; k++) {
            count++;
            r -= dr[d];
            c -= dc[d];
        }

        if (count >= 4) return 1;
    }
    return 0;
}

int boardFull() {
    int j;
    for (j = 0; j < COLS; j++)
        if (board[0][j] == '.') return 0;
    return 1;
}

int main() {
    int turn, col, row, moves;
    char piece;

    initBoard();
    printf("=== Connect Four ===\n");
    printf("Players take turns dropping discs. Get 4 in a row to win.\n");

    for (moves = 0; moves < ROWS * COLS; moves++) {
        turn = moves % 2;
        piece = (turn == 0) ? 'X' : 'O';

        printBoard();
        printf("Player %c, choose a column (1-7): ", piece);

        if (scanf("%d", &col) != 1) {
            printf("Invalid input.\n");
            break;
        }
        col -= 1;

        row = dropDisc(col, piece);
        if (row == -1) {
            printf("Invalid move, column full or out of range. Try again.\n");
            moves--;
            continue;
        }

        if (checkWin(row, col, piece)) {
            printBoard();
            printf("Player %c wins!\n", piece);
            return 0;
        }
    }

    if (boardFull()) {
        printBoard();
        printf("It's a draw!\n");
    }

    return 0;
}
