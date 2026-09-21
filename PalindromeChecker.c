#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(const char *s) {
    int len = (int) strlen(s), i;
    for (i = 0; i < len / 2; i++) {
        if (tolower((unsigned char) s[i]) != tolower((unsigned char) s[len - 1 - i])) return 0;
    }
    return 1;
}

int main() {
    const char *words[6] = {"level", "hello", "radar", "world", "civic", "coding"};
    int i, score = 0, actual;

    printf("=== Palindrome Checker Game ===\nIs each word a palindrome? 1=yes, 0=no\n");

    for (i = 0; i < 6; i++) {
        actual = isPalindrome(words[i]);
        printf("\n%s - palindrome? ", words[i]);
        {
            int g;
            if (scanf("%d", &g) != 1) continue;
            if (g == actual) { printf("Correct!\n"); score++; }
            else printf("Wrong! %s is %sa palindrome.\n", words[i], actual ? "" : "not ");
        }
    }

    printf("\nFinal score: %d/6\n", score);
    return 0;
}
