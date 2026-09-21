#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    clock_t start, end;
    double elapsed;
    long delay;
    int rounds = 3, r;

    srand((unsigned int) time(NULL));
    printf("=== Traffic Light Reaction ===\nWait for GREEN, then press enter as fast as you can!\n");

    for (r = 1; r <= rounds; r++) {
        printf("\nRound %d\nRED...\n", r);
        delay = 1000000L * (2 + rand() % 3);
        { long i; for (i = 0; i < delay; i++) { } }
        printf("YELLOW...\n");
        delay = 500000L;
        { long i; for (i = 0; i < delay; i++) { } }
        printf("GREEN! GO! Press enter: ");
        start = clock();
        getchar();
        end = clock();

        elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Reaction time: %.3f seconds\n", elapsed);
    }

    printf("\nThanks for playing!\n");
    return 0;
}
