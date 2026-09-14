#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a, b, op, answer, correctAnswer, score = 0, rounds = 10, i;

    srand((unsigned int) time(NULL));
    printf("=== Math Quiz ===\n%d rounds of arithmetic. Good luck!\n", rounds);

    for (i = 1; i <= rounds; i++) {
        a = rand() % 50 + 1;
        b = rand() % 50 + 1;
        op = rand() % 3;

        if (op == 0) { correctAnswer = a + b; printf("\nQ%d: %d + %d = ? ", i, a, b); }
        else if (op == 1) { correctAnswer = a - b; printf("\nQ%d: %d - %d = ? ", i, a, b); }
        else { correctAnswer = a * b; printf("\nQ%d: %d * %d = ? ", i, a, b); }

        if (scanf("%d", &answer) != 1) { printf("Invalid input.\n"); continue; }

        if (answer == correctAnswer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The answer was %d.\n", correctAnswer);
        }
    }

    printf("\nFinal score: %d/%d\n", score, rounds);
    return 0;
}
