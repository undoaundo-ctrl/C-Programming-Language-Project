#include <stdio.h>

#define NUM_Q 5

int main() {
    const char *events[NUM_Q] = {
        "The Declaration of Independence was signed",
        "World War II ended",
        "The first man landed on the Moon",
        "The Berlin Wall fell",
        "The World Wide Web was invented"
    };
    int years[NUM_Q] = {1776, 1945, 1969, 1989, 1989};
    int guess, score = 0, i, diff;

    printf("=== Historical Year Quiz ===\nGuess the year of each event (closer = more points).\n");

    for (i = 0; i < NUM_Q; i++) {
        printf("\n%s. What year? ", events[i]);
        if (scanf("%d", &guess) != 1) continue;

        diff = guess - years[i];
        if (diff < 0) diff = -diff;

        if (diff == 0) { printf("Exact! +3 points\n"); score += 3; }
        else if (diff <= 5) { printf("Close! +1 point (actual: %d)\n", years[i]); score += 1; }
        else printf("Off by %d years. (actual: %d)\n", diff, years[i]);
    }

    printf("\nFinal score: %d\n", score);
    return 0;
}
