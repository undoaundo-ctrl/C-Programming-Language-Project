#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollTwoDice() { return (1 + rand() % 6) + (1 + rand() % 6); }

int main() {
    int point, roll, credits = 100, bet;

    srand((unsigned int) time(NULL));
    printf("=== Craps ===\nYou start with %d credits.\n", credits);

    while (credits > 0) {
        printf("\nCredits: %d\n", credits);
        printf("Enter your bet (0 to quit): ");
        if (scanf("%d", &bet) != 1 || bet < 0 || bet > credits) { printf("Invalid bet.\n"); continue; }
        if (bet == 0) break;

        roll = rollTwoDice();
        printf("Come-out roll: %d\n", roll);

        if (roll == 7 || roll == 11) {
            printf("Natural! You win!\n");
            credits += bet;
            continue;
        }
        if (roll == 2 || roll == 3 || roll == 12) {
            printf("Craps! You lose.\n");
            credits -= bet;
            continue;
        }

        point = roll;
        printf("Point is %d. Rolling until you hit %d or 7.\n", point, point);
        do {
            roll = rollTwoDice();
            printf("Rolled: %d\n", roll);
        } while (roll != point && roll != 7);

        if (roll == point) {
            printf("You made your point! You win!\n");
            credits += bet;
        } else {
            printf("Seven out! You lose.\n");
            credits -= bet;
        }
    }

    printf("\nFinal credits: %d\n", credits);
    return 0;
}
