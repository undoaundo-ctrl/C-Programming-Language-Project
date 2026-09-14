#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollPins(int pinsLeft) {
    return rand() % (pinsLeft + 1);
}

int main() {
    int frame, roll1, roll2, totalScore = 0;

    srand((unsigned int) time(NULL));
    printf("=== Bowling Simulator ===\n");

    for (frame = 1; frame <= 10; frame++) {
        roll1 = rollPins(10);
        printf("\nFrame %d, Roll 1: %d pins\n", frame, roll1);

        if (roll1 == 10) {
            printf("STRIKE!\n");
            totalScore += 10;
            continue;
        }

        roll2 = rollPins(10 - roll1);
        printf("Frame %d, Roll 2: %d pins\n", frame, roll2);

        if (roll1 + roll2 == 10) printf("SPARE!\n");

        totalScore += roll1 + roll2;
    }

    printf("\nFinal score (simplified): %d\n", totalScore);
    return 0;
}
