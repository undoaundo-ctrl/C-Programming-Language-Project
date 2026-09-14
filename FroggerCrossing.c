#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LANES 5

int main() {
    int lane = 0, cars[LANES];
    int i;

    srand((unsigned int) time(NULL));
    printf("=== Frogger Crossing ===\nCross %d lanes of traffic. Roll to move, avoid cars!\n", LANES);

    while (lane < LANES) {
        for (i = 0; i < LANES; i++) cars[i] = rand() % 3; /* 0 = car present */

        printf("\nLane %d ahead: %s\n", lane + 1, cars[lane] == 0 ? "CAR COMING!" : "clear");
        printf("Press enter to hop forward...");
        getchar();

        if (cars[lane] == 0 && rand() % 2 == 0) {
            printf("SPLAT! You got hit by a car. Game over.\n");
            return 0;
        }

        lane++;
        printf("You hopped to lane %d.\n", lane);
    }

    printf("\nYou made it across safely! You win!\n");
    return 0;
}
