#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    clock_t start, end;
    double elapsed;
    int delay, rounds = 3, r;
    double totalTime = 0;

    printf("=== Reaction Time Test ===\nPress enter as fast as you can after 'GO!' appears.\n");

    srand((unsigned int) time(NULL));

    for (r = 1; r <= rounds; r++) {
        printf("\nRound %d - Get ready...\n", r);
        delay = 1000000 * (2 + rand() % 3);
        {
            long i;
            for (i = 0; i < delay; i++) { }
        }
        printf("GO! Press enter now: ");
        start = clock();
        getchar();
        end = clock();

        elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
        totalTime += elapsed;
        printf("Reaction time: %.3f seconds\n", elapsed);
    }

    printf("\nAverage reaction time: %.3f seconds\n", totalTime / rounds);
    return 0;
}
