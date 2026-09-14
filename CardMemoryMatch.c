#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PAIRS 6
#define CARDS (PAIRS * 2)

int main() {
    int cards[CARDS], revealed[CARDS] = {0};
    int i, j, temp, matchesFound = 0, attempts = 0;
    int a, b;

    srand((unsigned int) time(NULL));

    for (i = 0; i < PAIRS; i++) { cards[i * 2] = i; cards[i * 2 + 1] = i; }
    for (i = CARDS - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = cards[i]; cards[i] = cards[j]; cards[j] = temp;
    }

    printf("=== Card Memory Match ===\n%d cards, find all %d pairs.\n", CARDS, PAIRS);

    while (matchesFound < PAIRS) {
        printf("\nBoard: ");
        for (i = 0; i < CARDS; i++) {
            if (revealed[i]) printf("[%d]", cards[i]);
            else printf("[%d:?]", i);
        }
        printf("\n");

        printf("Pick first card index (0-%d): ", CARDS - 1);
        if (scanf("%d", &a) != 1 || a < 0 || a >= CARDS || revealed[a]) { printf("Invalid.\n"); continue; }
        printf("Pick second card index: ");
        if (scanf("%d", &b) != 1 || b < 0 || b >= CARDS || revealed[b] || a == b) { printf("Invalid.\n"); continue; }

        attempts++;
        printf("You revealed: %d and %d\n", cards[a], cards[b]);

        if (cards[a] == cards[b]) {
            printf("Match!\n");
            revealed[a] = 1;
            revealed[b] = 1;
            matchesFound++;
        } else {
            printf("No match, try to remember these positions.\n");
        }
    }

    printf("\nAll pairs found in %d attempts!\n", attempts);
    return 0;
}
