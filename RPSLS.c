#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char *names[5] = {"Rock", "Paper", "Scissors", "Lizard", "Spock"};

/* beats[a][b] = 1 if a beats b */
int beats(int a, int b) {
    static int table[5][5] = {
        {0,0,1,1,0},
        {1,0,0,0,1},
        {0,1,0,1,0},
        {0,1,1,0,1},
        {1,0,0,0,0}
    };
    return table[a][b];
}

int main() {
    int player, computer, rounds, i, playerScore = 0, computerScore = 0;

    srand((unsigned int) time(NULL));
    printf("=== Rock Paper Scissors Lizard Spock ===\n");
    printf("0=Rock 1=Paper 2=Scissors 3=Lizard 4=Spock\n");
    printf("How many rounds? ");
    if (scanf("%d", &rounds) != 1 || rounds <= 0) return 1;

    for (i = 1; i <= rounds; i++) {
        printf("\nRound %d - your choice: ", i);
        if (scanf("%d", &player) != 1 || player < 0 || player > 4) {
            printf("Invalid choice, skipping.\n");
            continue;
        }
        computer = rand() % 5;
        printf("You: %s | Computer: %s\n", names[player], names[computer]);

        if (player == computer) printf("Tie!\n");
        else if (beats(player, computer)) { printf("You win!\n"); playerScore++; }
        else { printf("Computer wins!\n"); computerScore++; }
    }

    printf("\nFinal score - You: %d, Computer: %d\n", playerScore, computerScore);
    return 0;
}
