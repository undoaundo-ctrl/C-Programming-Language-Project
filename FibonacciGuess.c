#include <stdio.h>

int main() {
    long fib[20];
    int i, guess, score = 0, rounds = 5, r;

    fib[0] = 0; fib[1] = 1;
    for (i = 2; i < 20; i++) fib[i] = fib[i - 1] + fib[i - 2];

    printf("=== Fibonacci Guess ===\nGuess the next number in the Fibonacci sequence.\n");

    for (r = 1; r <= rounds; r++) {
        int start = r;
        printf("\nRound %d: ", r);
        for (i = start; i < start + 4; i++) printf("%ld, ", fib[i]);
        printf("? ");

        if (scanf("%d", &guess) != 1) continue;

        if (guess == fib[start + 4]) { printf("Correct!\n"); score++; }
        else printf("Wrong! The answer was %ld\n", fib[start + 4]);
    }

    printf("\nFinal score: %d/%d\n", score, rounds);
    return 0;
}
