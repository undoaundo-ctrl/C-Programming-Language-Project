#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numTickets, myTicket, winningTicket;

    srand((unsigned int) time(NULL));
    printf("=== Lucky Draw Raffle ===\nHow many tickets are in the raffle? ");
    if (scanf("%d", &numTickets) != 1 || numTickets < 1) return 1;

    printf("Pick your ticket number (1-%d): ", numTickets);
    if (scanf("%d", &myTicket) != 1 || myTicket < 1 || myTicket > numTickets) return 1;

    winningTicket = 1 + rand() % numTickets;
    printf("\nDrawing the winning ticket...\n");
    printf("Winning ticket: %d\n", winningTicket);

    if (myTicket == winningTicket) printf("\nCONGRATULATIONS! You won the raffle!\n");
    else printf("\nSorry, not a winner this time. Try again!\n");

    return 0;
}
