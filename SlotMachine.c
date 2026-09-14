#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char *symbols[5] = {"Cherry", "Lemon", "Bell", "Star", "Diamond"};

int main() {
    int credits = 50, bet, s1, s2, s3;
    char again;

    srand((unsigned int) time(NULL));
    printf("=== Slot Machine ===\nYou start with %d credits.\n", credits);

    do {
        printf("\nCredits: %d\n", credits);
        if (credits <= 0) { printf("Out of credits!\n"); break; }
        printf("Bet amount: ");
        if (scanf("%d", &bet) != 1 || bet < 1 || bet > credits) { printf("Invalid bet.\n"); continue; }

        s1 = rand() % 5;
        s2 = rand() % 5;
        s3 = rand() % 5;
        printf("[ %s | %s | %s ]\n", symbols[s1], symbols[s2], symbols[s3]);

        if (s1 == s2 && s2 == s3) {
            printf("JACKPOT! You win %d credits!\n", bet * 10);
            credits += bet * 10;
        } else if (s1 == s2 || s2 == s3 || s1 == s3) {
            printf("Two match! You win %d credits!\n", bet * 2);
            credits += bet * 2;
        } else {
            printf("No match. You lose %d credits.\n", bet);
            credits -= bet;
        }

        printf("Spin again? (y/n): ");
        scanf(" %c", &again);
    } while (again == 'y' || again == 'Y');

    printf("\nFinal credits: %d\n", credits);
    return 0;
}
