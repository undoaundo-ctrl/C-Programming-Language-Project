#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char *colors[4] = {"Red", "Green", "Blue", "Yellow"};

int main() {
    int playerHand[7], computerHand[7], discardColor, discardNum, i;

    srand((unsigned int) time(NULL));
    for (i = 0; i < 7; i++) { playerHand[i] = rand() % 10; }
    for (i = 0; i < 7; i++) { computerHand[i] = rand() % 10; }
    discardColor = rand() % 4;
    discardNum = rand() % 10;

    printf("=== Uno (simplified, numbers 0-9) ===\n");
    printf("Top card: %s %d\n", colors[discardColor], discardNum);

    printf("\nYour hand: ");
    for (i = 0; i < 7; i++) printf("%d ", playerHand[i]);
    printf("\n");

    printf("Play a card number matching the discard number, or type -1 to draw: ");
    {
        int play;
        scanf("%d", &play);
        if (play == discardNum) {
            printf("Nice play! You matched the number.\n");
        } else {
            printf("You draw a card (simplified penalty).\n");
        }
    }

    printf("\nComputer plays its turn...\n");
    {
        int matched = 0;
        for (i = 0; i < 7; i++) {
            if (computerHand[i] == discardNum) {
                printf("Computer matched with %d\n", computerHand[i]);
                matched = 1;
                break;
            }
        }
        if (!matched) printf("Computer had to draw.\n");
    }

    printf("\nRound complete! Thanks for playing.\n");
    return 0;
}
