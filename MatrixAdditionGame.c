#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a[2][2], b[2][2], guess[2][2], i, j, correct = 1;

    srand((unsigned int) time(NULL));
    printf("=== Matrix Addition Game ===\nAdd two 2x2 matrices.\n");

    printf("Matrix A:\n");
    for (i = 0; i < 2; i++) { for (j = 0; j < 2; j++) { a[i][j] = rand() % 10; printf("%d ", a[i][j]); } printf("\n"); }

    printf("\nMatrix B:\n");
    for (i = 0; i < 2; i++) { for (j = 0; j < 2; j++) { b[i][j] = rand() % 10; printf("%d ", b[i][j]); } printf("\n"); }

    printf("\nEnter your answer matrix (A+B), 4 numbers row by row: ");
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            if (scanf("%d", &guess[i][j]) != 1) return 1;

    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            if (guess[i][j] != a[i][j] + b[i][j]) correct = 0;

    if (correct) printf("\nCorrect! Great matrix addition!\n");
    else {
        printf("\nWrong! The correct answer was:\n");
        for (i = 0; i < 2; i++) { for (j = 0; j < 2; j++) printf("%d ", a[i][j] + b[i][j]); printf("\n"); }
    }

    return 0;
}
