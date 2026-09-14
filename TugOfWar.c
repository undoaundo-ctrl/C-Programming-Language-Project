#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int position = 0, pull, rounds = 0;

    srand((unsigned int) time(NULL));
    printf("=== Tug of War ===\nType a number (1-10) to pull the rope. Reach +10 or -10 to win.\n");
    printf("Positive pulls the rope your way, computer pulls randomly.\n");

    while (position > -10 && position < 10) {
        printf("\nRope position: %d (You are at 10, Computer is at -10)\n", position);
        printf("Pull strength (1-10): ");
        if (scanf("%d", &pull) != 1 || pull < 1 || pull > 10) { printf("Invalid.\n"); continue; }

        position += pull;
        printf("You pulled %d.\n", pull);

        if (position >= 10) break;

        pull = 1 + rand() % 10;
        position -= pull;
        printf("Computer pulled %d.\n", pull);

        rounds++;
    }

    if (position <= -10) printf("\nThe computer wins the tug of war!\n");
    else printf("\nYou win the tug of war!\n");

    return 0;
}
