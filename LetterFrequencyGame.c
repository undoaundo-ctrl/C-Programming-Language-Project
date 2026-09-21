#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    const char *words[4] = {"mississippi", "bookkeeper", "committee", "assessment"};
    int w;

    printf("=== Letter Frequency Game ===\nGuess the most frequent letter in each word.\n");

    for (w = 0; w < 4; w++) {
        int counts[26] = {0};
        char guess;
        int len = (int) strlen(words[w]), j, maxCount = 0;
        char maxLetter = 'a';

        for (j = 0; j < len; j++) counts[words[w][j] - 'a']++;
        for (j = 0; j < 26; j++) if (counts[j] > maxCount) { maxCount = counts[j]; maxLetter = (char) ('a' + j); }

        printf("\n%s - most frequent letter? ", words[w]);
        scanf(" %c", &guess);
        guess = (char) tolower((unsigned char) guess);

        if (guess == maxLetter) printf("Correct! It appears %d times.\n", maxCount);
        else printf("Wrong! It was '%c' (%d times).\n", maxLetter, maxCount);
    }

    return 0;
}
