#include <stdio.h>

#define SIZE 8

char maze[SIZE][SIZE + 1] = {
    "########",
    "#S..#..#",
    "#.##...#",
    "#....#.#",
    "##.#.#.#",
    "#..#...#",
    "#.####.#",
    "#......E"
};

int main() {
    int px = 1, py = 1, ex = 7, ey = 7, i, j;
    char move;
    int nx, ny;

    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            if (maze[i][j] == 'S') { py = i; px = j; }
            else if (maze[i][j] == 'E') { ey = i; ex = j; }

    printf("=== Maze ===\nReach E. Controls: w/a/s/d, q to quit\n");

    while (!(px == ex && py == ey)) {
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                if (i == py && j == px) printf("@");
                else printf("%c", maze[i][j]);
            }
            printf("\n");
        }
        printf("Move: ");
        if (scanf(" %c", &move) != 1) break;
        if (move == 'q') { printf("Bye!\n"); return 0; }

        nx = px; ny = py;
        if (move == 'w') ny--;
        else if (move == 's') ny++;
        else if (move == 'a') nx--;
        else if (move == 'd') nx++;
        else { printf("Invalid.\n"); continue; }

        if (nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE || maze[ny][nx] == '#') {
            printf("Can't move there.\n");
            continue;
        }
        px = nx; py = ny;
    }

    printf("\nYou reached the exit! Congratulations!\n");
    return 0;
}
