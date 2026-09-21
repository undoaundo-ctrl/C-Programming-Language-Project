#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char *colorNames[4] = {"Red", "Blue", "Green", "Yellow"};

int main() {
    int sequence[20];
    int level = 3, i, guess, correct;

    srand((unsigned int) time(NULL));
    for (i = 0; i < 20; i++) sequence[i] = rand() % 4;

    printf("=== Color Simon ===\nMemorize the color sequence, then enter each as 0=Red,1=Blue,2=Green,3=Yellow.\n");

    while (level <= 20) {
        printf("\nLevel %d - Sequence: ", level - 2);
        for (i = 0; i < level; i++) printf("%s ", colorNames[sequence[i]]);
        printf("\nPress enter once memorized...");
        getchar();
        getchar();

        correct = 1;
        for (i = 0; i < level; i++) {
            printf("Color %d: ", i + 1);
            if (scanf("%d", &guess) != 1 || guess != sequence[i]) correct = 0;
        }

        if (!correct) { printf("\nWrong! You reached level %d.\n", level - 2); return 0; }
        printf("Correct! Next level.\n");
        level++;
    }

    printf("\nAmazing memory! You beat all levels!\n");
    return 0;
}
