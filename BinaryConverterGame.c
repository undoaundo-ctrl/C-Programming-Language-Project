#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void toBinary(int n, char *out) {
    int i, bits[16], count = 0;
    if (n == 0) { strcpy(out, "0"); return; }
    while (n > 0) { bits[count++] = n % 2; n /= 2; }
    for (i = 0; i < count; i++) out[i] = (char) ('0' + bits[count - 1 - i]);
    out[count] = '\0';
}

int main() {
    int num, score = 0, rounds = 6, i;
    char guess[20], correct[20];

    srand((unsigned int) time(NULL));
    printf("=== Binary Converter Game ===\nConvert the decimal number to binary.\n");

    for (i = 1; i <= rounds; i++) {
        num = rand() % 64;
        toBinary(num, correct);
        printf("\nConvert %d to binary: ", num);
        scanf("%19s", guess);

        if (strcmp(guess, correct) == 0) { printf("Correct!\n"); score++; }
        else printf("Wrong! %d in binary is %s\n", num, correct);
    }

    printf("\nFinal score: %d/%d\n", score, rounds);
    return 0;
}
