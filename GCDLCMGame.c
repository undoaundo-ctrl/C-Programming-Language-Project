#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gcd(int a, int b) { while (b) { int t = b; b = a % b; a = t; } return a; }

int main() {
    int a, b, guess, score = 0, rounds = 5, i, choice;

    srand((unsigned int) time(NULL));
    printf("=== GCD and LCM Game ===\n");

    for (i = 1; i <= rounds; i++) {
        a = 2 + rand() % 30;
        b = 2 + rand() % 30;
        choice = rand() % 2;

        if (choice == 0) {
            printf("\nWhat is the GCD of %d and %d? ", a, b);
            if (scanf("%d", &guess) != 1) continue;
            if (guess == gcd(a, b)) { printf("Correct!\n"); score++; }
            else printf("Wrong! GCD is %d\n", gcd(a, b));
        } else {
            int lcm = (a * b) / gcd(a, b);
            printf("\nWhat is the LCM of %d and %d? ", a, b);
            if (scanf("%d", &guess) != 1) continue;
            if (guess == lcm) { printf("Correct!\n"); score++; }
            else printf("Wrong! LCM is %d\n", lcm);
        }
    }

    printf("\nFinal score: %d/%d\n", score, rounds);
    return 0;
}
