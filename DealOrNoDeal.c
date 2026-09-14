#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CASES 10

int main() {
    int values[NUM_CASES] = {1, 5, 10, 50, 100, 500, 1000, 5000, 10000, 100000};
    int used[NUM_CASES] = {0};
    int myCase, pick, i, remaining = NUM_CASES, offer;

    srand((unsigned int) time(NULL));
    printf("=== Deal or No Deal ===\nPick your case (1-%d), then open others.\n", NUM_CASES);
    printf("Your case: ");
    scanf("%d", &myCase);
    if (myCase < 1 || myCase > NUM_CASES) return 1;
    used[myCase - 1] = 1;
    remaining--;

    while (remaining > 1) {
        printf("\nOpen a case (1-%d): ", NUM_CASES);
        if (scanf("%d", &pick) != 1 || pick < 1 || pick > NUM_CASES || used[pick - 1]) {
            printf("Invalid.\n");
            continue;
        }
        used[pick - 1] = 1;
        remaining--;
        printf("Case %d had $%d\n", pick, values[pick - 1]);

        offer = 0;
        for (i = 0; i < NUM_CASES; i++) if (!used[i]) offer += values[i];
        offer = offer / (remaining + 1);
        printf("Banker offers: $%d. Deal or no deal? (1=deal, 0=no deal): ", offer);
        {
            int choice;
            scanf("%d", &choice);
            if (choice == 1) {
                printf("\nYou took the deal! You win $%d\n", offer);
                return 0;
            }
        }
    }

    printf("\nYour case (%d) contained: $%d\n", myCase, values[myCase - 1]);
    return 0;
}
