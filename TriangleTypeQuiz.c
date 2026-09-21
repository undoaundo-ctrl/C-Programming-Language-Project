#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void toLower(char *s) { while (*s) { *s = (char) tolower((unsigned char) *s); s++; } }

const char* classify(int a, int b, int c) {
    if (a == b && b == c) return "equilateral";
    if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a) return "right";
    if (a == b || b == c || a == c) return "isosceles";
    return "scalene";
}

int main() {
    int sides[5][3] = {{3,4,5},{5,5,5},{5,5,8},{6,7,9},{3,4,7}};
    char guess[20];
    int i, score = 0;

    printf("=== Triangle Type Quiz ===\nGiven three sides, is it equilateral, isosceles, scalene, or right?\n");

    for (i = 0; i < 4; i++) {
        printf("\nSides: %d, %d, %d - type? ", sides[i][0], sides[i][1], sides[i][2]);
        scanf("%19s", guess);
        toLower(guess);

        {
            const char *correct = classify(sides[i][0], sides[i][1], sides[i][2]);
            if (strcmp(guess, correct) == 0) { printf("Correct!\n"); score++; }
            else printf("Answer: %s\n", correct);
        }
    }

    printf("\nFinal score: %d/4\n", score);
    return 0;
}
