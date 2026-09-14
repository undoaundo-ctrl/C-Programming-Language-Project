#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_HORSES 4
#define TRACK_LEN 15

int main() {
    int positions[NUM_HORSES] = {0}, myHorse, i, roll, winner = -1;

    srand((unsigned int) time(NULL));
    printf("=== Horse Race ===\n%d horses race to %d. Pick your horse (0-%d): ", NUM_HORSES, TRACK_LEN, NUM_HORSES - 1);
    if (scanf("%d", &myHorse) != 1 || myHorse < 0 || myHorse >= NUM_HORSES) return 1;

    while (winner == -1) {
        for (i = 0; i < NUM_HORSES; i++) {
            roll = 1 + rand() % 3;
            positions[i] += roll;
            if (positions[i] >= TRACK_LEN && winner == -1) winner = i;
        }

        printf("\n");
        for (i = 0; i < NUM_HORSES; i++) {
            int p, j;
            printf("Horse %d: ", i);
            p = positions[i] > TRACK_LEN ? TRACK_LEN : positions[i];
            for (j = 0; j < p; j++) printf("=");
            printf(">\n");
        }
    }

    printf("\nHorse %d wins the race!\n", winner);
    if (winner == myHorse) printf("You picked the winner! Congratulations!\n");
    else printf("Better luck next time!\n");

    return 0;
}
