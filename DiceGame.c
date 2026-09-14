#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
    return (rand() % 6) + 1;
}

int main() {
    int credits = 100;
    int bet, guess, roll, playAgain;

    srand((unsigned int) time(NULL));

    printf("=== Dice Guessing Game ===\n");
    printf("You start with %d credits.\n", credits);
    printf("Guess the dice roll (1-6) and bet credits. Correct guess pays 5x your bet.\n");

    do {
        printf("\nCredits: %d\n", credits);

        if (credits <= 0) {
            printf("You're out of credits! Game over.\n");
            break;
        }

        printf("Enter your bet (1-%d): ", credits);
        if (scanf("%d", &bet) != 1 || bet < 1 || bet > credits) {
            printf("Invalid bet.\n");
            continue;
        }

        printf("Guess the roll (1-6): ");
        if (scanf("%d", &guess) != 1 || guess < 1 || guess > 6) {
            printf("Invalid guess.\n");
            continue;
        }

        roll = rollDice();
        printf("The dice rolled: %d\n", roll);

        if (roll == guess) {
            printf("Correct! You win %d credits.\n", bet * 5);
            credits += bet * 5;
        } else {
            printf("Wrong! You lose %d credits.\n", bet);
            credits -= bet;
        }

        printf("Play again? (1 = yes, 0 = no): ");
        if (scanf("%d", &playAgain) != 1) break;

    } while (playAgain == 1 && credits > 0);

    printf("\nFinal credits: %d\n", credits);
    printf("Thanks for playing!\n");

    return 0;
}
