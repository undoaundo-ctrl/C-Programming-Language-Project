#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const char *conditions[5] = {"Sunny", "Rainy", "Cloudy", "Snowy", "Windy"};
    int guess, actual, score = 0, rounds = 5, i;

    srand((unsigned int) time(NULL));
    printf("=== Weather Prediction Game ===\nPredict tomorrow's weather! 0=Sunny 1=Rainy 2=Cloudy 3=Snowy 4=Windy\n");

    for (i = 1; i <= rounds; i++) {
        printf("\nDay %d prediction: ", i);
        if (scanf("%d", &guess) != 1 || guess < 0 || guess > 4) { printf("Invalid.\n"); continue; }

        actual = rand() % 5;
        printf("Actual weather: %s\n", conditions[actual]);

        if (guess == actual) { printf("Correct prediction!\n"); score++; }
        else printf("Wrong prediction.\n");
    }

    printf("\nFinal score: %d/%d\n", score, rounds);
    return 0;
}
