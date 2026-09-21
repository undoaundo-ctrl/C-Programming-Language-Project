#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int count, malfunction;

    srand((unsigned int) time(NULL));
    printf("=== Rocket Launch Countdown ===\n");

    for (count = 10; count >= 1; count--) {
        printf("%d...\n", count);
    }

    malfunction = rand() % 5;
    if (malfunction == 0) {
        printf("\nWARNING! Engine malfunction detected! Launch aborted.\n");
    } else {
        printf("\nLIFTOFF! The rocket soars into the sky!\n");
    }

    return 0;
}
