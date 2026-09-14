#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rounds, i, playerRoll, computerRoll, playerWins = 0, computerWins = 0;

    srand((unsigned int) time(NULL));
    printf("=== Dice Duel ===\nHighest roll each round wins. How many rounds? ");
    if (scanf("%d", &rounds) != 1 || rounds <= 0) return 1;

    for (i = 1; i <= rounds; i++) {
        playerRoll = 1 + rand() % 6;
        computerRoll = 1 + rand() % 6;
        printf("\nRound %d - You: %d, Computer: %d\n", i, playerRoll, computerRoll);

        if (playerRoll > computerRoll) { printf("You win the round!\n"); playerWins++; }
        else if (playerRoll < computerRoll) { printf("Computer wins the round!\n"); computerWins++; }
        else printf("Tie!\n");
    }

    printf("\nFinal - You: %d, Computer: %d\n", playerWins, computerWins);
    if (playerWins > computerWins) printf("You win the duel!\n");
    else if (playerWins < computerWins) printf("Computer wins the duel!\n");
    else printf("The duel is a draw!\n");

    return 0;
}
