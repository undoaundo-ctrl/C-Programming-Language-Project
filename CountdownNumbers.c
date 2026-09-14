#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int nums[6], target, i;

    srand((unsigned int) time(NULL));
    printf("=== Countdown Numbers Game ===\n");

    for (i = 0; i < 6; i++) nums[i] = 1 + rand() % 20;
    target = 100 + rand() % 400;

    printf("Numbers: ");
    for (i = 0; i < 6; i++) printf("%d ", nums[i]);
    printf("\nTarget: %d\n", target);
    printf("Use the numbers with +, -, *, / to reach the target exactly (or as close as possible).\n");
    printf("This is a thinking challenge - work it out on paper! Type your closest result when ready: ");

    {
        int guess, diff;
        if (scanf("%d", &guess) == 1) {
            diff = guess - target;
            if (diff < 0) diff = -diff;
            printf("\nYour result: %d (target was %d, difference: %d)\n", guess, target, diff);
            if (diff == 0) printf("Perfect! Exact match!\n");
            else if (diff <= 5) printf("Very close! Nice work.\n");
            else printf("Keep practicing!\n");
        }
    }

    return 0;
}
