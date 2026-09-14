#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerCard, computerCard, rounds, i, playerWins = 0, computerWins = 0;

    srand((unsigned int) time(NULL));
    printf("=== Card War ===\nHigher card wins each round (2-14, 14=Ace).\n");
    printf("How many rounds? ");
    if (scanf("%d", &rounds) != 1 || rounds <= 0) return 1;

    for (i = 1; i <= rounds; i++) {
        playerCard = 2 + rand() % 13;
        computerCard = 2 + rand() % 13;
        printf("\nRound %d - You: %d, Computer: %d\n", i, playerCard, computerCard);

        if (playerCard > computerCard) { printf("You win the round!\n"); playerWins++; }
        else if (playerCard < computerCard) { printf("Computer wins the round!\n"); computerWins++; }
        else printf("Tie!\n");
    }

    printf("\nFinal - You: %d, Computer: %d\n", playerWins, computerWins);
    if (playerWins > computerWins) printf("You win the war!\n");
    else if (playerWins < computerWins) printf("Computer wins the war!\n");
    else printf("The war is a draw!\n");

    return 0;
}
