#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isPrime(int n) {
    int i;
    if (n < 2) return 0;
    for (i = 2; i * i <= n; i++) if (n % i == 0) return 0;
    return 1;
}

int main() {
    int num, guess, score = 0, rounds = 10, i;

    srand((unsigned int) time(NULL));
    printf("=== Prime Checker ===\nIs the number prime? 1=yes, 0=no\n");

    for (i = 1; i <= rounds; i++) {
        num = 2 + rand() % 100;
        printf("\nIs %d prime? ", num);
        if (scanf("%d", &guess) != 1) continue;

        if ((guess == 1) == isPrime(num)) { printf("Correct!\n"); score++; }
        else printf("Wrong! %d is %sprime.\n", num, isPrime(num) ? "" : "not ");
    }

    printf("\nFinal score: %d/%d\n", score, rounds);
    return 0;
}
