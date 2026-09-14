#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const char *prizes[8] = {"$100", "Bankrupt", "$500", "Lose a turn", "$1000", "$250", "Free spin", "$50"};
    int spin;
    char again;

    srand((unsigned int) time(NULL));
    printf("=== Spin the Wheel ===\n");

    do {
        printf("\nPress enter to spin...");
        getchar();
        spin = rand() % 8;
        printf("The wheel lands on: %s\n", prizes[spin]);

        printf("Spin again? (y/n): ");
        scanf(" %c", &again);
    } while (again == 'y' || again == 'Y');

    printf("Thanks for playing!\n");
    return 0;
}
