#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRACK_LEN 25
#define NUM_CARS 3

int main() {
    int pos[NUM_CARS] = {0}, i, roll, winner = -1, lap = 0;

    srand((unsigned int) time(NULL));
    printf("=== Car Race ===\n%d cars race to %d. Watch it play out!\n", NUM_CARS, TRACK_LEN);

    while (winner == -1) {
        lap++;
        for (i = 0; i < NUM_CARS; i++) {
            roll = 1 + rand() % 5;
            pos[i] += roll;
            if (pos[i] >= TRACK_LEN && winner == -1) winner = i;
        }

        printf("\nLap %d:\n", lap);
        for (i = 0; i < NUM_CARS; i++) {
            int p = pos[i] > TRACK_LEN ? TRACK_LEN : pos[i];
            int j;
            printf("Car %d: ", i + 1);
            for (j = 0; j < p; j++) printf("-");
            printf(">\n");
        }
    }

    printf("\nCar %d wins the race!\n", winner + 1);
    return 0;
}
