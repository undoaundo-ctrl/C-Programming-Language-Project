#include <stdio.h>

#define SIZE 5

char grid1[SIZE][SIZE], grid2[SIZE][SIZE];
int ship1Row, ship1Col, ship2Row, ship2Col;

void initGrids() {
    int i, j;
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++) { grid1[i][j] = '.'; grid2[i][j] = '.'; }
}

void printGrid(char g[SIZE][SIZE]) {
    int i, j;
    printf("\n   ");
    for (j = 0; j < SIZE; j++) printf("%d ", j);
    printf("\n");
    for (i = 0; i < SIZE; i++) {
        printf("%2d ", i);
        for (j = 0; j < SIZE; j++) printf("%c ", g[i][j]);
        printf("\n");
    }
}

int main() {
    int row, col, turn = 1;

    initGrids();
    printf("=== Battleship (2 Player, hotseat) ===\n");
    printf("Player 1, place your ship (row col): ");
    scanf("%d %d", &ship1Row, &ship1Col);
    printf("Player 2, place your ship (row col): ");
    scanf("%d %d", &ship2Row, &ship2Col);
    printf("\n(Screen would normally clear here for privacy)\n");

    while (1) {
        if (turn == 1) {
            printf("\nPlayer 1's turn - fire at Player 2's grid:\n");
            printGrid(grid2);
            printf("Row Col: ");
            scanf("%d %d", &row, &col);
            if (row == ship2Row && col == ship2Col) {
                printf("HIT! Player 1 wins!\n");
                break;
            }
            grid2[row][col] = 'O';
            printf("Miss!\n");
        } else {
            printf("\nPlayer 2's turn - fire at Player 1's grid:\n");
            printGrid(grid1);
            printf("Row Col: ");
            scanf("%d %d", &row, &col);
            if (row == ship1Row && col == ship1Col) {
                printf("HIT! Player 2 wins!\n");
                break;
            }
            grid1[row][col] = 'O';
            printf("Miss!\n");
        }
        turn = 3 - turn;
    }

    return 0;
}
