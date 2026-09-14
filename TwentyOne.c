#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int count = 0, add, playerTurn = 1;

    srand((unsigned int) time(NULL));
    printf("=== Twenty-One (counting game) ===\n");
    printf("Take turns adding 1, 2, or 3 to the count. Whoever says 21 loses!\n");

    while (count < 21) {
        if (playerTurn) {
            printf("\nCurrent count: %d\nAdd 1, 2, or 3: ", count);
            if (scanf("%d", &add) != 1 || add < 1 || add > 3 || count + add > 21) {
                printf("Invalid move.\n");
                continue;
            }
            count += add;
            printf("Count is now %d\n", count);
        } else {
            add = (21 - count <= 3) ? (21 - count - 1 > 0 ? 21 - count - 1 : 1) : (1 + rand() % 3);
            if (count + add > 21) add = 21 - count;
            count += add;
            printf("\nComputer added %d. Count is now %d\n", add, count);
        }

        if (count == 21) {
            if (playerTurn) printf("\nYou said 21! You lose!\n");
            else printf("\nComputer said 21! You win!\n");
            break;
        }

        playerTurn = !playerTurn;
    }

    return 0;
}
