#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char *ranks[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
const char *suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

int main() {
    int rank, suit, guessRank, guessSuit, score = 0;

    srand((unsigned int) time(NULL));
    rank = rand() % 13;
    suit = rand() % 4;

    printf("=== Guess the Card ===\nI'm thinking of a card from a standard deck.\n");
    printf("Guess the rank (0-12, 0=Ace...12=King): ");
    if (scanf("%d", &guessRank) != 1) return 1;
    printf("Guess the suit (0=Hearts,1=Diamonds,2=Clubs,3=Spades): ");
    if (scanf("%d", &guessSuit) != 1) return 1;

    if (guessRank == rank) { printf("Correct rank!\n"); score++; }
    if (guessSuit == suit) { printf("Correct suit!\n"); score++; }

    printf("\nThe card was: %s of %s\n", ranks[rank], suits[suit]);

    if (score == 2) printf("PERFECT! You guessed the exact card!\n");
    else if (score == 1) printf("Close! You got one part right.\n");
    else printf("No match this time.\n");

    return 0;
}
