#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 20

int main() {
    int sequence[MAX_LEN];
    int level = 3, i, guess, correct;

    srand((unsigned int) time(NULL));
    for (i = 0; i < MAX_LEN; i++) sequence[i] = 1 + rand() % 4;

    printf("=== Simon Says ===\nMemorize the sequence of numbers (1-4), then repeat it.\n");

    while (level <= MAX_LEN) {
        printf("\nLevel %d - Sequence: ", level - 2);
        for (i = 0; i < level; i++) printf("%d ", sequence[i]);
        printf("\n(Memorize it, then press enter)\n");
        getchar();
        printf("Press enter when ready to input: ");
        getchar();

        correct = 1;
        for (i = 0; i < level; i++) {
            printf("Enter number %d: ", i + 1);
            if (scanf("%d", &guess) != 1 || guess != sequence[i]) {
                correct = 0;
            }
        }

        if (!correct) {
            printf("\nWrong sequence! You reached level %d.\n", level - 2);
            return 0;
        }

        printf("Correct! Moving to next level.\n");
        level++;
    }

    printf("\nAmazing! You completed all levels!\n");
    return 0;
}
