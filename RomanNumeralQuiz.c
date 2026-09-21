#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void toRoman(int n, char *out) {
    int values[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    const char *symbols[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int i;
    out[0] = '\0';
    for (i = 0; i < 13; i++) {
        while (n >= values[i]) { strcat(out, symbols[i]); n -= values[i]; }
    }
}

int main() {
    int num, score = 0, rounds = 6, i;
    char guess[20], correct[20];

    srand((unsigned int) time(NULL));
    printf("=== Roman Numeral Quiz ===\nConvert the number to Roman numerals.\n");

    for (i = 1; i <= rounds; i++) {
        num = 1 + rand() % 99;
        toRoman(num, correct);
        printf("\nConvert %d to Roman numerals: ", num);
        scanf("%19s", guess);

        if (strcmp(guess, correct) == 0) { printf("Correct!\n"); score++; }
        else printf("Wrong! %d is %s\n", num, correct);
    }

    printf("\nFinal score: %d/%d\n", score, rounds);
    return 0;
}
