#include <stdio.h>
#include <string.h>

int main() {
    int num, score = 0, rounds = 10, i;
    char guess[20];
    char correct[20];

    printf("=== FizzBuzz Challenge ===\nType Fizz for multiples of 3, Buzz for 5, FizzBuzz for both, or the number itself.\n");

    for (i = 1, num = 1; i <= rounds; i++, num++) {
        if (num % 15 == 0) sprintf(correct, "FizzBuzz");
        else if (num % 3 == 0) sprintf(correct, "Fizz");
        else if (num % 5 == 0) sprintf(correct, "Buzz");
        else sprintf(correct, "%d", num);

        printf("\nNumber %d: ", num);
        scanf("%19s", guess);

        if (strcmp(guess, correct) == 0) { printf("Correct!\n"); score++; }
        else printf("Wrong! Should be: %s\n", correct);
    }

    printf("\nFinal score: %d/%d\n", score, rounds);
    return 0;
}
