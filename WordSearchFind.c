#include <stdio.h>
#include <string.h>

#define SIZE 6

char grid[SIZE][SIZE + 1] = {
    "CATDOG",
    "AXBYRZ",
    "TQWERT",
    "DOGCAT",
    "MNOPQR",
    "SUNFUN"
};

int main() {
    char word[20];
    int found = 0, i, j, k, len;

    printf("=== Word Search ===\n");
    for (i = 0; i < SIZE; i++) printf("%s\n", grid[i]);

    printf("\nEnter a word to find (horizontally, left to right): ");
    scanf("%19s", word);
    len = (int) strlen(word);

    for (i = 0; i < SIZE && !found; i++) {
        for (j = 0; j <= SIZE - len && !found; j++) {
            int match = 1;
            for (k = 0; k < len; k++) {
                if (grid[i][j + k] != word[k]) { match = 0; break; }
            }
            if (match) {
                found = 1;
                printf("\nFound '%s' at row %d, starting column %d!\n", word, i, j);
            }
        }
    }

    if (!found) printf("\n'%s' not found horizontally in the grid.\n", word);

    return 0;
}
