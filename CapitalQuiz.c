#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_Q 6

void toLower(char *s) { while (*s) { *s = (char) tolower((unsigned char) *s); s++; } }

int main() {
    const char *countries[NUM_Q] = {"Italy", "Germany", "Canada", "Egypt", "Brazil", "Australia"};
    const char *capitals[NUM_Q] = {"rome", "berlin", "ottawa", "cairo", "brasilia", "canberra"};
    char guess[100];
    int score = 0, i;

    printf("=== Capital Cities Quiz ===\n");

    for (i = 0; i < NUM_Q; i++) {
        printf("\nWhat is the capital of %s? > ", countries[i]);
        getchar();
        fgets(guess, sizeof(guess), stdin);
        guess[strcspn(guess, "\n")] = 0;
        toLower(guess);

        if (strcmp(guess, capitals[i]) == 0) { printf("Correct!\n"); score++; }
        else printf("Wrong! Answer: %s\n", capitals[i]);
    }

    printf("\nFinal score: %d/%d\n", score, NUM_Q);
    return 0;
}
