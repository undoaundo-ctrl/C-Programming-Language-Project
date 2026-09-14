#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int sticks, take, computerTake, playerTurn;

    srand((unsigned int) time(NULL));

    printf("=== Nim ===\n");
    printf("Rules: Take 1-3 sticks per turn. Whoever takes the LAST stick loses.\n");

    sticks = 15 + rand() % 6; /* between 15 and 20 sticks */
    printf("Starting sticks: %d\n", sticks);

    playerTurn = 1;

    while (sticks > 0) {
        printf("\nSticks remaining: %d\n", sticks);

        if (playerTurn) {
            printf("Your turn. Take 1-3 sticks: ");
            if (scanf("%d", &take) != 1 || take < 1 || take > 3 || take > sticks) {
                printf("Invalid move, try again.\n");
                continue;
            }
            sticks -= take;
            printf("You took %d stick(s).\n", take);
        } else {
            /* simple computer strategy: try to leave a multiple of 4 sticks */
            computerTake = sticks % 4;
            if (computerTake == 0 || computerTake > 3) computerTake = 1 + rand() % 3;
            if (computerTake > sticks) computerTake = sticks;
            sticks -= computerTake;
            printf("Computer took %d stick(s).\n", computerTake);
        }

        if (sticks == 0) {
            if (playerTurn) {
                printf("\nYou took the last stick. You lose!\n");
            } else {
                printf("\nComputer took the last stick. You win!\n");
            }
            break;
        }

        playerTurn = !playerTurn;
    }

    return 0;
}
