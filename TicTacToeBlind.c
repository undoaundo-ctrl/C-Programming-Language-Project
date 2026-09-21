#include <stdio.h>

char board[9];

int checkWin(char p) {
    int wins[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int i;
    for (i = 0; i < 8; i++)
        if (board[wins[i][0]] == p && board[wins[i][1]] == p && board[wins[i][2]] == p) return 1;
    return 0;
}

int boardFull() {
    int i;
    for (i = 0; i < 9; i++) if (board[i] == ' ') return 0;
    return 1;
}

int main() {
    int move, turn;
    char player;
    int i;

    for (i = 0; i < 9; i++) board[i] = ' ';

    printf("=== Tic-Tac-Toe Blind ===\nNo board is shown! Remember your moves and play from memory.\n");

    for (turn = 0; turn < 9; turn++) {
        player = (turn % 2 == 0) ? 'X' : 'O';
        printf("\nPlayer %c, enter position (1-9): ", player);

        if (scanf("%d", &move) != 1 || move < 1 || move > 9 || board[move - 1] != ' ') {
            printf("Invalid move (or already taken).\n");
            turn--;
            continue;
        }

        board[move - 1] = player;

        if (checkWin(player)) {
            printf("\nPlayer %c wins! Revealing board:\n", player);
            for (i = 0; i < 9; i += 3) printf(" %c | %c | %c \n", board[i], board[i+1], board[i+2]);
            return 0;
        }
    }

    if (boardFull()) {
        printf("\nIt's a draw! Revealing board:\n");
        for (i = 0; i < 9; i += 3) printf(" %c | %c | %c \n", board[i], board[i+1], board[i+2]);
    }

    return 0;
}
