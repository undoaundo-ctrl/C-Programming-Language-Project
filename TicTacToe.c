#include <stdio.h>

char board[3][3];

void initBoard() {
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void printBoard() {
    int i;
    printf("\n");
    for (i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("---+---+---\n");
    }
    printf("\n");
}

int checkWin(char player) {
    int i;
    for (i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return 1;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return 1;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return 1;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return 1;
    return 0;
}

int boardFull() {
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (board[i][j] == ' ') return 0;
    return 1;
}

int main() {
    int row, col, turn;
    char player;

    initBoard();
    printf("=== Tic-Tac-Toe ===\n");
    printf("Enter row and column (0-2) to place your mark.\n");

    for (turn = 0; turn < 9; turn++) {
        player = (turn % 2 == 0) ? 'X' : 'O';
        printBoard();
        printf("Player %c, enter row and column: ", player);

        if (scanf("%d %d", &row, &col) != 2) {
            printf("Invalid input.\n");
            break;
        }

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move, try again.\n");
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

    if (boardFull()) {
        printBoard();
        printf("It's a draw!\n");
    }

    return 0;
}
