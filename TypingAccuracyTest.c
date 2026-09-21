#include <stdio.h>
#include <string.h>

int main() {
    char target[] = "practice makes perfect every single day";
    char input[200];
    int matches = 0, len, i;

    printf("=== Typing Accuracy Test ===\nType this sentence exactly:\n\n%s\n\n> ", target);
    getchar();
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    len = (int) strlen(target);
    for (i = 0; i < len && input[i]; i++) {
        if (input[i] == target[i]) matches++;
    }

    printf("\nAccuracy: %.1f%%\n", (matches * 100.0) / len);
    if (matches == len && strlen(input) == (size_t) len) printf("Perfect!\n");

    return 0;
}
