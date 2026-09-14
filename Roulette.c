#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int credits = 100, bet, choice, result, isRed;

    srand((unsigned int) time(NULL));
    printf("=== Roulette (simplified) ===\nBet on Red(1), Black(0), or a number 0-36.\n");
    printf("You start with %d credits.\n", credits);

    while (credits > 0) {
        printf("\nCredits: %d\n", credits);
        printf("Bet amount (0 to quit): ");
        if (scanf("%d", &bet) != 1 || bet < 0 || bet > credits) { printf("Invalid.\n"); continue; }
        if (bet == 0) break;

        printf("Bet type: 1=Red, 0=Black, 2=Exact number\n> ");
        if (scanf("%d", &choice) != 1) continue;

        result = rand() % 37; /* 0-36 */
        isRed = (result != 0) && (result % 2 == 1); /* simplified parity rule */
        printf("Ball landed on: %d (%s)\n", result, result == 0 ? "Green" : (isRed ? "Red" : "Black"));

        if (choice == 2) {
            int num;
            printf("Which number did you bet? ");
            scanf("%d", &num);
            if (num == result) { printf("Exact hit! You win big!\n"); credits += bet * 20; }
            else { printf("No match. You lose.\n"); credits -= bet; }
        } else if ((choice == 1 && isRed) || (choice == 0 && !isRed && result != 0)) {
            printf("You win!\n");
            credits += bet;
        } else {
            printf("You lose.\n");
            credits -= bet;
        }
    }

    printf("\nFinal credits: %d\n", credits);
    return 0;
}
