#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int actual, guess, diff;

    srand((unsigned int) time(NULL));
    actual = 50 + rand() % 200; /* between 50 and 249 */

    printf("=== Jellybean Jar Guessing ===\nHow many jellybeans are in the jar? Closest guess wins!\n");
    printf("Your guess: ");
    if (scanf("%d", &guess) != 1) return 1;

    diff = guess - actual;
    if (diff < 0) diff = -diff;

    printf("\nThe jar had %d jellybeans. You guessed %d.\n", actual, guess);
    if (diff == 0) printf("PERFECT! You counted exactly right!\n");
    else if (diff <= 5) printf("Amazing guess! Off by only %d.\n", diff);
    else if (diff <= 20) printf("Pretty close! Off by %d.\n", diff);
    else printf("Not quite! Off by %d.\n", diff);

    return 0;
}
