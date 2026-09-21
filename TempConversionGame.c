#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int celsius, guess, score = 0, rounds = 5, i, correctF;

    srand((unsigned int) time(NULL));
    printf("=== Temperature Conversion Game ===\nConvert Celsius to Fahrenheit (round to nearest whole number).\n");

    for (i = 1; i <= rounds; i++) {
        celsius = rand() % 100;
        correctF = (int) (celsius * 9.0 / 5.0 + 32 + 0.5);
        printf("\n%d C = ? F ", celsius);
        if (scanf("%d", &guess) != 1) continue;

        if (guess >= correctF - 1 && guess <= correctF + 1) { printf("Correct!\n"); score++; }
        else printf("Wrong! %d C = %d F\n", celsius, correctF);
    }

    printf("\nFinal score: %d/%d\n", score, rounds);
    return 0;
}
