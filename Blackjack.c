#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int drawCard() {
    int card = 1 + rand() % 13;
    if (card > 10) card = 10;
    return card;
}

int main() {
    int playerTotal = 0, dealerTotal = 0, card, choice;

    srand((unsigned int) time(NULL));
    printf("=== Blackjack ===\n");

    playerTotal += drawCard();
    playerTotal += drawCard();
    dealerTotal += drawCard();

    printf("Your total: %d\n", playerTotal);
    printf("Dealer shows: %d\n", dealerTotal);

    while (playerTotal < 21) {
        printf("Hit or stand? (1=hit, 0=stand): ");
        if (scanf("%d", &choice) != 1) break;
        if (choice == 0) break;
        card = drawCard();
        playerTotal += card;
        printf("You drew %d. Total: %d\n", card, playerTotal);
    }

    if (playerTotal > 21) {
        printf("Bust! You lose.\n");
        return 0;
    }

    dealerTotal += drawCard();
    while (dealerTotal < 17) {
        card = drawCard();
        dealerTotal += card;
        printf("Dealer drew %d. Dealer total: %d\n", card, dealerTotal);
    }

    printf("\nFinal - You: %d, Dealer: %d\n", playerTotal, dealerTotal);

    if (dealerTotal > 21 || playerTotal > dealerTotal) printf("You win!\n");
    else if (playerTotal == dealerTotal) printf("Push (tie)!\n");
    else printf("Dealer wins!\n");

    return 0;
}
