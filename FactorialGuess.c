#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long factorial(int n) {
    long result = 1;
    int i;
    for (i = 2; i <= n; i++) result *= i;
    return result;
}

int main() {
    int n, guess, score = 0, rounds = 5, i;

    srand((unsigned int) time(NULL));
    printf("=== Factorial Guess ===\nCompute n! for small n.\n");

    for (i = 1; i <= rounds; i++) {
        n = 1 + rand() % 8;
        printf("\nWhat is %d! ? ", n);
        if (scanf("%d", &guess) != 1) continue;

        if (guess == factorial(n)) { printf("Correct!\n"); score++; }
        else printf("Wrong! %d! = %ld\n", n, factorial(n));
    }

    printf("\nFinal score: %d/%d\n", score, rounds);
    return 0;
}
