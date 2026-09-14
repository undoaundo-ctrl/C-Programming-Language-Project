#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDie() { return 1 + rand() % 6; }

int main() {
    int playerScore = 0, computerScore = 0, turnScore, roll, choice;
    int target = 50;

    srand((unsigned int) time(NULL));
    printf("=== Pig ===\nFirst to %d points wins. Roll a 1 and you lose your turn score!\n", target);

    while (playerScore < target && computerScore < target) {
        turnScore = 0;
        printf("\n-- Your turn -- (Score: %d)\n", playerScore);
        do {
            roll = rollDie();
            printf("You rolled: %d\n", roll);
            if (roll == 1) {
                printf("Busted! You lose your turn score.\n");
                turnScore = 0;
                break;
            }
            turnScore += roll;
            printf("Turn score: %d. Roll again? (1=yes, 0=hold): ", turnScore);
            if (scanf("%d", &choice) != 1) choice = 0;
        } while (choice == 1);
        playerScore += turnScore;

        if (playerScore >= target) break;

        turnScore = 0;
        printf("\n-- Computer's turn -- (Score: %d)\n", computerScore);
        do {
            roll = rollDie();
            printf("Computer rolled: %d\n", roll);
            if (roll == 1) { turnScore = 0; printf("Computer busted!\n"); break; }
            turnScore += roll;
        } while (turnScore < 20);
        computerScore += turnScore;
        printf("Computer's turn score: %d\n", turnScore);
    }

    printf("\nFinal - You: %d, Computer: %d\n", playerScore, computerScore);
    if (playerScore >= target) printf("You win!\n");
    else printf("Computer wins!\n");

    return 0;
}
