#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a, b, answer, score = 0, rounds = 5, i;
    clock_t start, end;
    double totalTime = 0, elapsed;

    srand((unsigned int) time(NULL));
    printf("=== Speed Math Challenge ===\nAnswer as fast as you can!\n");

    for (i = 1; i <= rounds; i++) {
        a = rand() % 20 + 1;
        b = rand() % 20 + 1;
        printf("\nQ%d: %d + %d = ? ", i, a, b);

        start = clock();
        if (scanf("%d", &answer) != 1) continue;
        end = clock();

        elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
        totalTime += elapsed;

        if (answer == a + b) {
            printf("Correct! (%.2f sec)\n", elapsed);
            score++;
        } else {
            printf("Wrong! Answer was %d. (%.2f sec)\n", a + b, elapsed);
        }
    }

    printf("\nScore: %d/%d, Total time: %.2f sec, Avg: %.2f sec/question\n",
           score, rounds, totalTime, totalTime / rounds);
    return 0;
}
