#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define MAXLEN 100

int main() {
    int snakeX[MAXLEN], snakeY[MAXLEN], len = 1;
    int foodX, foodY, dx = 1, dy = 0, newX, newY;
    char dir;
    int i, j, alive = 1;
    char grid[SIZE][SIZE];

    srand((unsigned int) time(NULL));
    snakeX[0] = SIZE / 2;
    snakeY[0] = SIZE / 2;
    foodX = rand() % SIZE;
    foodY = rand() % SIZE;

    printf("=== Snake ===\nControls: w/a/s/d each turn, q to quit\n");

    while (alive) {
        for (i = 0; i < SIZE; i++)
            for (j = 0; j < SIZE; j++)
                grid[i][j] = '.';
        grid[foodY][foodX] = 'F';
        for (i = 0; i < len; i++) grid[snakeY[i]][snakeX[i]] = 'O';

        printf("\n");
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) printf("%c ", grid[i][j]);
            printf("\n");
        }
        printf("Score: %d\n", len - 1);
        printf("Move (w/a/s/d/q): ");
        if (scanf(" %c", &dir) != 1) break;
        if (dir == 'q') { printf("Bye!\n"); break; }
        if (dir == 'w') { dx = 0; dy = -1; }
        else if (dir == 's') { dx = 0; dy = 1; }
        else if (dir == 'a') { dx = -1; dy = 0; }
        else if (dir == 'd') { dx = 1; dy = 0; }
        else { printf("Invalid move.\n"); continue; }

        newX = snakeX[0] + dx;
        newY = snakeY[0] + dy;
        if (newX < 0 || newX >= SIZE || newY < 0 || newY >= SIZE) {
            printf("You hit the wall! Game over.\n");
            break;
        }
        for (i = 0; i < len; i++) {
            if (snakeX[i] == newX && snakeY[i] == newY) alive = 0;
        }
        if (!alive) { printf("You hit yourself! Game over.\n"); break; }

        for (i = len; i > 0; i--) { snakeX[i] = snakeX[i - 1]; snakeY[i] = snakeY[i - 1]; }
        snakeX[0] = newX;
        snakeY[0] = newY;

        if (newX == foodX && newY == foodY && len < MAXLEN - 1) {
            len++;
            foodX = rand() % SIZE;
            foodY = rand() % SIZE;
            printf("Yum! Score: %d\n", len - 1);
        }
    }
    return 0;
}
