#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DIGITS 15

int main() {
    int digits[MAX_DIGITS];
    int level = 3, i, guess, correct;

    srand((unsigned int) time(NULL));
    printf("=== Number Memory ===\nMemorize the growing number sequence.\n");

    for (i = 0; i < MAX_DIGITS; i++) digits[i] = rand() % 10;

    while (level <= MAX_DIGITS) {
        printf("\nLevel %d - Remember: ", level - 2);
        for (i = 0; i < level; i++) printf("%d", digits[i]);
        printf("\n");
        printf("Press enter once memorized...");
        getchar();
        getchar();

        correct = 1;
        for (i = 0; i < level; i++) {
            printf("Digit %d: ", i + 1);
            if (scanf("%d", &guess) != 1 || guess != digits[i]) correct = 0;
        }

        if (!correct) {
            printf("\nWrong! You reached level %d.\n", level - 2);
            return 0;
        }
        printf("Correct! Next level.\n");
        level++;
    }

    printf("\nIncredible memory! You beat all levels!\n");
    return 0;
}
