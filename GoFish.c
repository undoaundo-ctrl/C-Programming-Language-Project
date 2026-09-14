#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HAND_SIZE 7

int main() {
    int playerHand[HAND_SIZE], computerHand[HAND_SIZE], i, ask, playerBooks = 0, computerBooks = 0;

    srand((unsigned int) time(NULL));
    for (i = 0; i < HAND_SIZE; i++) { playerHand[i] = 1 + rand() % 13; computerHand[i] = 1 + rand() % 13; }

    printf("=== Go Fish (simplified) ===\n");
    printf("Your hand: ");
    for (i = 0; i < HAND_SIZE; i++) printf("%d ", playerHand[i]);
    printf("\n");

    printf("Ask computer for a rank (1-13): ");
    if (scanf("%d", &ask) != 1) return 1;

    {
        int found = 0, j;
        for (j = 0; j < HAND_SIZE; j++) {
            if (computerHand[j] == ask) {
                printf("Go fish success! Computer had a %d.\n", ask);
                found = 1;
                computerHand[j] = 0;
            }
        }
        if (!found) printf("Go Fish! Computer had no %ds.\n", ask);

        {
            int count = 0;
            for (j = 0; j < HAND_SIZE; j++) if (playerHand[j] == ask) count++;
            if (found) count++;
            if (count >= 4) { playerBooks++; printf("You made a book of %ds!\n", ask); }
        }
    }

    printf("\nBooks - You: %d, Computer: %d\n", playerBooks, computerBooks);
    return 0;
}
