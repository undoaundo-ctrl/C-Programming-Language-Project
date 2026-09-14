#include <stdio.h>

int main() {
    int low = 1, high = 100, mid, response;

    printf("=== Reverse Number Guessing ===\n");
    printf("Think of a number between 1 and 100. I'll try to guess it!\n");
    printf("Respond with: 1 = too low, 2 = too high, 3 = correct\n");

    while (low <= high) {
        mid = (low + high) / 2;
        printf("\nIs your number %d? (1=too low, 2=too high, 3=correct): ", mid);
        if (scanf("%d", &response) != 1) break;

        if (response == 3) {
            printf("\nI guessed it! Your number was %d.\n", mid);
            return 0;
        } else if (response == 1) {
            low = mid + 1;
        } else if (response == 2) {
            high = mid - 1;
        } else {
            printf("Invalid response, please enter 1, 2, or 3.\n");
        }
    }

    printf("\nHmm, something doesn't add up with your responses!\n");
    return 0;
}
