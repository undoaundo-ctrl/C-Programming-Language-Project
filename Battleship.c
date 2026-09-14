#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define NUM_SHIPS 3

char grid[SIZE][SIZE];
int shipRow[NUM_SHIPS], shipCol[NUM_SHIPS], sunk[NUM_SHIPS];

void initGrid() {
    int i, j;
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            grid[i][j] = '.';
}

void placeShips() {
    int i, r, c, unique, k;
    for (i = 0; i < NUM_SHIPS; i++) {
        do {
            unique = 1;
            r = rand() % SIZE;
            c = rand() % SIZE;
            for (k = 0; k < i; k++) {
                if (shipRow[k] == r && shipCol[k] == c) unique = 0;
            }
        } while (!unique);
        shipRow[i] = r;
        shipCol[i] = c;
        sunk[i] = 0;
    }
}

void printGrid() {
    int i, j;
    printf("\n   ");
    for (j = 0; j < SIZE; j++) printf("%d ", j);
    printf("\n");
    for (i = 0; i < SIZE; i++) {
        printf("%2d ", i);
        for (j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int row, col, i, hits = 0, shots = 0, found;

    srand((unsigned int) time(NULL));
    initGrid();
    placeShips();

    printf("=== Battleship ===\n");
    printf("Sink all %d hidden ships on a %dx%d grid.\n", NUM_SHIPS, SIZE, SIZE);

    while (hits < NUM_SHIPS) {
        printGrid();
        printf("Enter row and column to fire: ");

        if (scanf("%d %d", &row, &col) != 2) {
            printf("Invalid input.\n");
            break;
        }

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
            printf("Out of bounds, try again.\n");
            continue;
        }

        if (grid[row][col] == 'X' || grid[row][col] == 'O') {
            printf("You already fired there.\n");
            continue;
        }

        shots++;
        found = 0;
        for (i = 0; i < NUM_SHIPS; i++) {
            if (shipRow[i] == row && shipCol[i] == col && !sunk[i]) {
                sunk[i] = 1;
                grid[row][col] = 'X';
                hits++;
                found = 1;
                printf("Hit! You sank a ship.\n");
                break;
            }
        }

        if (!found) {
            grid[row][col] = 'O';
            printf("Miss.\n");
        }
    }

    printGrid();
    printf("\nAll ships sunk in %d shots! You win!\n", shots);

    return 0;
}
