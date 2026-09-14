#include <stdio.h>

char board[9];

void printBoard() {
    int i;
    printf("\n");
    for (i = 0; i < 9; i += 3) {
        printf(" %c | %c | %c \n", board[i], board[i+1], board[i+2]);
        if (i < 6) printf("---+---+---\n");
    }
    printf("\n");
}

int checkWinner(char p) {
    int wins[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int i;
    for (i = 0; i < 8; i++) {
        if (board[wins[i][0]] == p && board[wins[i][1]] == p && board[wins[i][2]] == p) return 1;
    }
    return 0;
}

int boardFull() {
    int i;
    for (i = 0; i < 9; i++) if (board[i] == ' ') return 0;
    return 1;
}

void computerMove() {
    int i;
    /* try to win */
    for (i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            board[i] = 'O';
            if (checkWinner('O')) return;
            board[i] = ' ';
        }
    }
    /* block player */
    for (i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            board[i] = 'X';
            if (checkWinner('X')) { board[i] = 'O'; return; }
            board[i] = ' ';
        }
    }
    /* take center, else first open */
    if (board[4] == ' ') { board[4] = 'O'; return; }
    for (i = 0; i < 9; i++) {
        if (board[i] == ' ') { board[i] = 'O'; return; }
    }
}

int main() {
    int move, i;

    for (i = 0; i < 9; i++) board[i] = ' ';

    printf("=== Tic-Tac-Toe vs Computer ===\nYou are X. Positions are numbered 1-9.\n");

    while (1) {
        printBoard();
        printf("Your move (1-9): ");
        if (scanf("%d", &move) != 1 || move < 1 || move > 9 || board[move - 1] != ' ') {
            printf("Invalid move.\n");
            continue;
        }
        board[move - 1] = 'X';

        if (checkWinner('X')) { printBoard(); printf("You win!\n"); break; }
        if (boardFull()) { printBoard(); printf("It's a draw!\n"); break; }

        computerMove();
        if (checkWinner('O')) { printBoard(); printf("Computer wins!\n"); break; }
        if (boardFull()) { printBoard(); printf("It's a draw!\n"); break; }
    }

    return 0;
}
