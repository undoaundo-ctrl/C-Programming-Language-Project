#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

int grid[SIZE][SIZE];

void toggle(int r, int c) {
    if (r >= 0 && r < SIZE && c >= 0 && c < SIZE) grid[r][c] = !grid[r][c];
}

void press(int r, int c) {
    toggle(r, c);
    toggle(r - 1, c);
    toggle(r + 1, c);
    toggle(r, c - 1);
    toggle(r, c + 1);
}

void printGrid() {
    int i, j;
    printf("\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) printf("%c ", grid[i][j] ? 'O' : '.');
        printf("\n");
    }
}

int allOff() {
    int i, j;
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            if (grid[i][j]) return 0;
    return 1;
}

int main() {
    int r, c, i, presses = 0;

    srand((unsigned int) time(NULL));
    for (i = 0; i < 8; i++) press(rand() % SIZE, rand() % SIZE);

    printf("=== Lights Out ===\nTurn off all lights. Pressing a cell toggles it and its neighbors.\n");

    while (!allOff()) {
        printGrid();
        printf("Press row and column: ");
        if (scanf("%d %d", &r, &c) != 2 || r < 0 || r >= SIZE || c < 0 || c >= SIZE) {
            printf("Invalid.\n");
            continue;
        }
        press(r, c);
        presses++;
    }

    printGrid();
    printf("\nAll lights off! Solved in %d presses!\n", presses);
    return 0;
}
