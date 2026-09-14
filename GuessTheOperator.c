#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a, b, result, op, guess, score = 0, rounds = 8, i;

    srand((unsigned int) time(NULL));
    printf("=== Guess the Operator ===\nFigure out which operator (+,-,*) was used.\n");
    printf("Enter: 1 for +, 2 for -, 3 for *\n");

    for (i = 1; i <= rounds; i++) {
        a = 1 + rand() % 10;
        b = 1 + rand() % 10;
        op = 1 + rand() % 3;

        if (op == 1) result = a + b;
        else if (op == 2) result = a - b;
        else result = a * b;

        printf("\nRound %d: %d ? %d = %d\nWhich operator? ", i, a, b, result);
        if (scanf("%d", &guess) != 1) continue;

        if (guess == op) { printf("Correct!\n"); score++; }
        else printf("Wrong!\n");
    }

    printf("\nFinal score: %d/%d\n", score, rounds);
    return 0;
}
