#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 50
#define MAX_LEN 30

int main() {
    char words[MAX_WORDS][MAX_LEN];
    int count = 0, i;
    char newWord[MAX_LEN];
    char lastChar;

    printf("=== Word Chain ===\n");
    printf("Each word must start with the last letter of the previous word.\n");
    printf("No repeats allowed. Type 'quit' to stop.\n");

    printf("\nStart with any word: ");
    scanf("%29s", words[count]);
    count++;

    while (count < MAX_WORDS) {
        lastChar = (char) tolower((unsigned char) words[count - 1][strlen(words[count - 1]) - 1]);

        printf("\nNext word (must start with '%c'): ", lastChar);
        scanf("%29s", newWord);

        if (strcmp(newWord, "quit") == 0) break;

        if (tolower((unsigned char) newWord[0]) != lastChar) {
            printf("Word must start with '%c'. Try again.\n", lastChar);
            continue;
        }

        for (i = 0; i < count; i++) {
            if (strcmp(words[i], newWord) == 0) {
                printf("Word already used! Try again.\n");
                goto skip;
            }
        }

        strcpy(words[count], newWord);
        count++;
        printf("Chain length: %d\n", count);
        continue;
        skip:;
    }

    printf("\nFinal chain length: %d words\n", count);
    return 0;
}
