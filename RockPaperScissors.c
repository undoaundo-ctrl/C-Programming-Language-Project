#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const char *names[3] = {"Rock", "Paper", "Scissors"};

int beats(int a, int b) {
    if (a == 0 && b == 2) return 1;
    if (a == 1 && b == 0) return 1;
    if (a == 2 && b == 1) return 1;
    return 0;
}

int main() {
    int playerScore = 0, computerScore = 0, rounds, i;
    int playerChoice, computerChoice;

    srand((unsigned int) time(NULL));

    printf("=== Rock, Paper, Scissors ===\n");
    printf("How many rounds do you want to play? ");
    if (scanf("%d", &rounds) != 1 || rounds <= 0) {
        printf("Invalid number of rounds.\n");
        return 1;
    }

    for (i = 1; i <= rounds; i++) {
        printf("\nRound %d\n", i);
        printf("Choose: 0 = Rock, 1 = Paper, 2 = Scissors: ");
        if (scanf("%d", &playerChoice) != 1 || playerChoice < 0 || playerChoice > 2) {
            printf("Invalid choice, skipping round.\n");
            continue;
        }

        computerChoice = rand() % 3;
        printf("You chose %s. Computer chose %s.\n", names[playerChoice], names[computerChoice]);

        if (playerChoice == computerChoice) {
            printf("It's a tie!\n");
        } else if (beats(playerChoice, computerChoice)) {
            printf("You win this round!\n");
            playerScore++;
        } else {
            printf("Computer wins this round!\n");
            computerScore++;
        }
    }

    printf("\n=== Final Score ===\n");
    printf("You: %d | Computer: %d\n", playerScore, computerScore);

    if (playerScore > computerScore) printf("You win the game!\n");
    else if (playerScore < computerScore) printf("Computer wins the game!\n");
    else printf("The game is a tie!\n");

    return 0;
}
