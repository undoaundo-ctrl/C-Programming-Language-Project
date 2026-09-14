#include <stdio.h>

#define NUM_ROUNDS 5

int main() {
    int groups[NUM_ROUNDS][4] = {
        {2, 4, 6, 7},
        {3, 5, 9, 8},
        {10, 20, 25, 30},
        {1, 4, 9, 10},
        {12, 15, 18, 19}
    };
    const char *hints[NUM_ROUNDS] = {
        "Three are even, one is odd",
        "Three are odd, one is even",
        "Three are divisible by 5, one is not",
        "Three are perfect squares, one is not",
        "Three are divisible by 3, one is not"
    };
    int answers[NUM_ROUNDS] = {3, 3, 3, 3, 3};
    int guess, score = 0, r, i;

    printf("=== Odd One Out ===\nFind the number that doesn't belong.\n");

    for (r = 0; r < NUM_ROUNDS; r++) {
        printf("\nRound %d (%s): ", r + 1, hints[r]);
        for (i = 0; i < 4; i++) printf("%d ", groups[r][i]);
        printf("\nWhich index (0-3) is the odd one out? ");
        if (scanf("%d", &guess) != 1) continue;

        if (guess == answers[r]) { printf("Correct!\n"); score++; }
        else printf("Wrong! It was index %d (%d)\n", answers[r], groups[r][answers[r]]);
    }

    printf("\nFinal score: %d/%d\n", score, NUM_ROUNDS);
    return 0;
}
