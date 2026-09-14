#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int computerMove() { return rand() % 3; }

int beats(int a, int b) {
    return (a == 0 && b == 2) || (a == 1 && b == 0) || (a == 2 && b == 1);
}

int main() {
    const char *names[3] = {"Rock", "Paper", "Scissors"};
    int players = 4, wins[4] = {0}, round, move[4], i, j;

    srand((unsigned int) time(NULL));
    printf("=== RPS Tournament (you vs 3 computer players) ===\n");

    for (round = 1; round <= 3; round++) {
        printf("\n-- Round %d --\nYour move (0=Rock,1=Paper,2=Scissors): ", round);
        if (scanf("%d", &move[0]) != 1 || move[0] < 0 || move[0] > 2) { printf("Invalid.\n"); round--; continue; }

        for (i = 1; i < players; i++) move[i] = computerMove();

        for (i = 0; i < players; i++) printf("Player %d played %s\n", i, names[move[i]]);

        for (i = 0; i < players; i++)
            for (j = 0; j < players; j++)
                if (i != j && beats(move[i], move[j])) wins[i]++;
    }

    printf("\n=== Final Standings ===\n");
    for (i = 0; i < players; i++) printf("Player %d: %d wins\n", i, wins[i]);

    {
        int best = 0;
        for (i = 1; i < players; i++) if (wins[i] > wins[best]) best = i;
        printf("\nPlayer %d wins the tournament!\n", best);
    }

    return 0;
}
