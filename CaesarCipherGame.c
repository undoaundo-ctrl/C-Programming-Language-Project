#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encode(char *text, int shift) {
    int i;
    for (i = 0; text[i]; i++) {
        if (isupper((unsigned char) text[i])) text[i] = (char) ('A' + (text[i] - 'A' + shift + 26) % 26);
        else if (islower((unsigned char) text[i])) text[i] = (char) ('a' + (text[i] - 'a' + shift + 26) % 26);
    }
}

int main() {
    char message[] = "HELLO WORLD";
    char encoded[100];
    char guess[100];
    int shift = 3;

    strcpy(encoded, message);
    encode(encoded, shift);

    printf("=== Caesar Cipher Challenge ===\n");
    printf("This message was encoded with a shift of %d:\n%s\n", shift, encoded);
    printf("Decode it: ");
    scanf(" %[^\n]", guess);

    if (strcmp(guess, message) == 0) {
        printf("\nCorrect! You decoded the message!\n");
    } else {
        printf("\nNot quite. The original message was: %s\n", message);
    }

    return 0;
}
