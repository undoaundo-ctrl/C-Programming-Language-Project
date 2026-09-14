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

int checkThreeInRow(char p) {
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

int main() {
    int move, i, turn;
    char player;

    for (i = 0; i < 9; i++) board[i] = ' ';

    printf("=== Tic-Tac-Toe Misere (reverse rules!) ===\n");
    printf("Getting 3 in a row makes YOU LOSE. Avoid it!\n");

    for (turn = 0; turn < 9; turn++) {
        player = (turn % 2 == 0) ? 'X' : 'O';
        printBoard();
        printf("Player %c, enter position (1-9): ", player);

        if (scanf("%d", &move) != 1 || move < 1 || move > 9 || board[move - 1] != ' ') {
            printf("Invalid move.\n");
            turn--;
            continue;
        }

        board[move - 1] = player;

        if (checkThreeInRow(player)) {
            printBoard();
            printf("Player %c got 3 in a row and LOSES! Player %c wins!\n", player, player == 'X' ? 'O' : 'X');
            return 0;
        }
    }

    if (boardFull()) { printBoard(); printf("It's a draw!\n"); }
    return 0;
}
