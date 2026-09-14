#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int beats(int a, int b) {
    return (a == 0 && b == 2) || (a == 1 && b == 0) || (a == 2 && b == 1);
}

int main() {
    const char *names[3] = {"Rock", "Paper", "Scissors"};
    int history[3] = {0, 0, 0};
    int player, computer, rounds, i, playerScore = 0, computerScore = 0;

    srand((unsigned int) time(NULL));
    printf("=== Adaptive Rock Paper Scissors ===\nThe computer learns from your patterns!\n");
    printf("How many rounds? ");
    if (scanf("%d", &rounds) != 1 || rounds <= 0) return 1;

    for (i = 1; i <= rounds; i++) {
        printf("\nRound %d - your move (0=Rock,1=Paper,2=Scissors): ", i);
        if (scanf("%d", &player) != 1 || player < 0 || player > 2) { printf("Invalid.\n"); i--; continue; }

        history[player]++;

        if (i <= 2) {
            computer = rand() % 3;
        } else {
            int mostCommon = 0;
            int j;
            for (j = 1; j < 3; j++) if (history[j] > history[mostCommon]) mostCommon = j;
            computer = (mostCommon + 1) % 3;
        }

        printf("You: %s | Computer: %s\n", names[player], names[computer]);

        if (player == computer) printf("Tie!\n");
        else if (beats(player, computer)) { printf("You win!\n"); playerScore++; }
        else { printf("Computer wins!\n"); computerScore++; }
    }

    printf("\nFinal - You: %d, Computer: %d\n", playerScore, computerScore);
    return 0;
}
