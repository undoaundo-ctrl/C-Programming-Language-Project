#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countVowels(const char *s) {
    int count = 0, i;
    for (i = 0; s[i]; i++) {
        char c = (char) tolower((unsigned char) s[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') count++;
    }
    return count;
}

int main() {
    const char *words[5] = {"elephant", "umbrella", "orchestra", "aquarium", "education"};
    int i, guess, score = 0;

    printf("=== Vowel Counter Challenge ===\nHow many vowels in each word?\n");

    for (i = 0; i < 5; i++) {
        printf("\n%s > ", words[i]);
        if (scanf("%d", &guess) != 1) continue;

        if (guess == countVowels(words[i])) { printf("Correct!\n"); score++; }
        else printf("Wrong! It has %d vowels.\n", countVowels(words[i]));
    }

    printf("\nFinal score: %d/5\n", score);
    return 0;
}
