#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ALIENS 10

int main() {
    int aliens[NUM_ALIENS], remaining = NUM_ALIENS, shot, misses = 0, maxMisses = 5;
    int i;

    srand((unsigned int) time(NULL));
    for (i = 0; i < NUM_ALIENS; i++) aliens[i] = 1;

    printf("=== Space Invaders (text) ===\nShoot aliens 0-%d. Miss %d times and you lose.\n", NUM_ALIENS - 1, maxMisses);

    while (remaining > 0 && misses < maxMisses) {
        printf("\nAliens: ");
        for (i = 0; i < NUM_ALIENS; i++) printf("%c", aliens[i] ? 'A' : '.');
        printf("\nFire at position (0-%d): ", NUM_ALIENS - 1);

        if (scanf("%d", &shot) != 1 || shot < 0 || shot >= NUM_ALIENS) { printf("Invalid.\n"); continue; }

        if (aliens[shot]) {
            printf("Direct hit!\n");
            aliens[shot] = 0;
            remaining--;
        } else {
            printf("Miss!\n");
            misses++;
        }
    }

    if (remaining == 0) printf("\nAll aliens destroyed! You win!\n");
    else printf("\nToo many misses! Earth has fallen.\n");

    return 0;
}
