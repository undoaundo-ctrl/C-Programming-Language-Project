#include <stdio.h>
#include <string.h>

int diffByOne(const char *a, const char *b) {
    int diff = 0, i;
    if (strlen(a) != strlen(b)) return 0;
    for (i = 0; a[i]; i++) if (a[i] != b[i]) diff++;
    return diff == 1;
}

int main() {
    char start[] = "cat";
    char end[] = "dog";
    char current[20];
    char next[20];
    int steps = 0;

    strcpy(current, start);

    printf("=== Word Ladder ===\nChange '%s' to '%s' one letter at a time, each step a valid transformation.\n", start, end);
    printf("(This version just checks each step changes exactly one letter - build your own chain!)\n");

    while (strcmp(current, end) != 0) {
        printf("\nCurrent word: %s\nNext word (change exactly one letter): ", current);
        scanf("%19s", next);

        if (strlen(next) != strlen(current)) {
            printf("Word must be the same length.\n");
            continue;
        }
        if (!diffByOne(current, next)) {
            printf("Must change exactly one letter.\n");
            continue;
        }

        strcpy(current, next);
        steps++;
        printf("Good step! (%d steps so far)\n", steps);
    }

    printf("\nYou reached '%s' in %d steps!\n", end, steps);
    return 0;
}
