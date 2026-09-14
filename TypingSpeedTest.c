#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
    char target[] = "the quick brown fox jumps over the lazy dog";
    char input[200];
    clock_t start, end;
    double seconds, wpm;
    int words;

    printf("=== Typing Speed Test ===\n");
    printf("Type this exactly, then press enter:\n\n%s\n\n", target);
    printf("Press enter to start...");
    getchar();

    start = clock();
    fgets(input, sizeof(input), stdin);
    end = clock();

    input[strcspn(input, "\n")] = 0;

    if (strcmp(input, target) != 0) {
        printf("\nText didn't match exactly. Try to type it precisely next time.\n");
    }

    seconds = ((double) (end - start)) / CLOCKS_PER_SEC;
    words = 9; /* word count of target sentence */
    wpm = (seconds > 0) ? (words / (seconds / 60.0)) : 0;

    printf("\nTime: %.2f seconds\n", seconds);
    printf("Speed: %.1f words per minute\n", wpm);

    return 0;
}
