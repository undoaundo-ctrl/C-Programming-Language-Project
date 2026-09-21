#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int casts = 5, i, fishSize, totalWeight = 0;
    char reel;

    srand((unsigned int) time(NULL));
    printf("=== Fishing Game ===\nCast your line %d times and see what you catch!\n", casts);

    for (i = 1; i <= casts; i++) {
        printf("\nCast %d - press enter to cast...", i);
        getchar();
        printf("Something's biting! Press enter to reel in: ");
        reel = (char) getchar();
        (void) reel;

        fishSize = 1 + rand() % 20;
        printf("You caught a fish weighing %d lbs!\n", fishSize);
        totalWeight += fishSize;
    }

    printf("\nTotal catch: %d lbs across %d casts!\n", totalWeight, casts);
    return 0;
}
