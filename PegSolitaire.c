#include <stdio.h>
#include <stdlib.h>

#define SIZE 7
char board[SIZE][SIZE];

void initBoard() {
    int i, j;
    const char layout[SIZE][SIZE + 1] = {
        "  OOO  ",
        "  OOO  ",
        "OOOOOOO",
        "OOO.OOO",
        "OOOOOOO",
        "  OOO  ",
        "  OOO  "
    };
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            board[i][j] = layout[i][j];
}

void printBoard() {
    int i, j;
    printf("\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) printf("%c ", board[i][j]);
        printf("\n");
    }
}

int countPegs() {
    int i, j, count = 0;
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            if (board[i][j] == 'O') count++;
    return count;
}

int main() {
    int r1, c1, r2, c2, mr, mc;

    initBoard();
    printf("=== Peg Solitaire ===\nJump one peg over another into an empty space to remove the middle peg.\n");
    printf("Enter: from_row from_col to_row to_col (-1 -1 -1 -1 to quit)\n");

    while (1) {
        printBoard();
        printf("Pegs remaining: %d\n", countPegs());
        printf("Move: ");
        if (scanf("%d %d %d %d", &r1, &c1, &r2, &c2) != 4) break;
        if (r1 == -1) { printf("Thanks for playing!\n"); break; }

        if (r1 < 0 || r1 >= SIZE || c1 < 0 || c1 >= SIZE || r2 < 0 || r2 >= SIZE || c2 < 0 || c2 >= SIZE) {
            printf("Out of bounds.\n");
            continue;
        }
        if (board[r1][c1] != 'O') { printf("No peg there.\n"); continue; }
        if (board[r2][c2] != '.') { printf("Destination not empty.\n"); continue; }

        mr = (r1 + r2) / 2;
        mc = (c1 + c2) / 2;

        if ((abs(r1 - r2) == 2 && c1 == c2) || (abs(c1 - c2) == 2 && r1 == r2)) {
            if (board[mr][mc] == 'O') {
                board[r1][c1] = '.';
                board[mr][mc] = '.';
                board[r2][c2] = 'O';
            } else {
                printf("No peg to jump over.\n");
            }
        } else {
            printf("Invalid jump - must move exactly 2 spaces in a line.\n");
        }
    }

    return 0;
}
