#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char *suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

int main() {
    int playerHand[7], i, topRank, topSuit, play, playSuit;

    srand((unsigned int) time(NULL));
    for (i = 0; i < 7; i++) playerHand[i] = 1 + rand() % 13;
    topRank = 1 + rand() % 13;
    topSuit = rand() % 4;

    printf("=== Crazy Eights (simplified) ===\n");
    printf("Top card: %d of %s\n", topRank, suits[topSuit]);

    printf("\nYour hand: ");
    for (i = 0; i < 7; i++) printf("%d ", playerHand[i]);
    printf("\n");

    printf("Play a card matching rank %d, or an 8 (wild), else type 0 to draw: ", topRank);
    if (scanf("%d", &play) != 1) return 1;

    if (play == 8) {
        printf("You played an 8! Choose new suit (0-3): ");
        scanf("%d", &playSuit);
        if (playSuit >= 0 && playSuit < 4) printf("New suit is now %s.\n", suits[playSuit]);
    } else if (play == topRank) {
        printf("Nice play! You matched the rank.\n");
    } else if (play == 0) {
        printf("You drew a card.\n");
    } else {
        printf("Invalid play, drawing instead.\n");
    }

    printf("\nRound complete!\n");
    return 0;
}
