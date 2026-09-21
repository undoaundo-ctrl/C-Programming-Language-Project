#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int power, angle, target, rounds = 5, r, totalScore = 0;

    srand((unsigned int) time(NULL));
    printf("=== Archery Game ===\nHit the target! Distance varies each round.\n");

    for (r = 1; r <= rounds; r++) {
        target = 20 + rand() % 60;
        printf("\nRound %d - Target distance: %d meters\n", r, target);
        printf("Enter your shot power (1-100): ");
        if (scanf("%d", &power) != 1) continue;
        printf("Enter your angle (1-90): ");
        if (scanf("%d", &angle) != 1) continue;

        {
            int estimatedDistance = (power * angle) / 45;
            int diff = estimatedDistance - target;
            if (diff < 0) diff = -diff;

            printf("Your arrow landed near %d meters.\n", estimatedDistance);
            if (diff <= 2) { printf("BULLSEYE! +10 points\n"); totalScore += 10; }
            else if (diff <= 5) { printf("Close hit! +5 points\n"); totalScore += 5; }
            else printf("Missed the target.\n");
        }
    }

    printf("\nFinal score: %d\n", totalScore);
    return 0;
}
