#include <stdio.h>

int main() {
    int base[5], pyramid[5][5], i, j;

    printf("=== Number Pyramid ===\nEnter 5 base numbers. Each level up sums adjacent pairs.\n");

    for (i = 0; i < 5; i++) {
        printf("Base number %d: ", i + 1);
        if (scanf("%d", &base[i]) != 1) return 1;
        pyramid[0][i] = base[i];
    }

    for (i = 1; i < 5; i++) {
        for (j = 0; j < 5 - i; j++) {
            pyramid[i][j] = pyramid[i - 1][j] + pyramid[i - 1][j + 1];
        }
    }

    printf("\nYour pyramid:\n");
    for (i = 4; i >= 0; i--) {
        int spaces = (4 - i) * 3;
        for (j = 0; j < spaces; j++) printf(" ");
        for (j = 0; j <= i; j++) printf("%4d", pyramid[4 - i][j]);
        printf("\n");
    }

    printf("\nTop of pyramid: %d\n", pyramid[4][0]);
    return 0;
}
