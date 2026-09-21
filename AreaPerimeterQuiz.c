#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int length, width, guessArea, guessPerimeter, score = 0, rounds = 4, i;

    srand((unsigned int) time(NULL));
    printf("=== Area and Perimeter Quiz ===\nCalculate area and perimeter of each rectangle.\n");

    for (i = 1; i <= rounds; i++) {
        length = 2 + rand() % 18;
        width = 2 + rand() % 18;

        printf("\nRectangle: length=%d, width=%d\n", length, width);
        printf("Area? ");
        if (scanf("%d", &guessArea) != 1) continue;
        printf("Perimeter? ");
        if (scanf("%d", &guessPerimeter) != 1) continue;

        {
            int correctArea = length * width;
            int correctPerimeter = 2 * (length + width);
            int correct = 0;
            if (guessArea == correctArea) { printf("Area correct!\n"); correct++; }
            else printf("Area wrong! Correct: %d\n", correctArea);
            if (guessPerimeter == correctPerimeter) { printf("Perimeter correct!\n"); correct++; }
            else printf("Perimeter wrong! Correct: %d\n", correctPerimeter);
            if (correct == 2) score++;
        }
    }

    printf("\nFully correct rounds: %d/%d\n", score, rounds);
    return 0;
}
