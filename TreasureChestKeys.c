#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int correctKey, guess, tries = 0, maxTries = 3;

    srand((unsigned int) time(NULL));
    correctKey = 1 + rand() % 5;

    printf("=== Treasure Chest Keys ===\nOne of 5 keys opens the chest. You have %d tries.\n", maxTries);

    while (tries < maxTries) {
        tries++;
        printf("\nTry %d - Pick a key (1-5): ", tries);
        if (scanf("%d", &guess) != 1) break;

        if (guess == correctKey) {
            printf("\nThe chest opens! You found the treasure!\n");
            return 0;
        }
        printf("That key doesn't fit.\n");
    }

    printf("\nOut of tries! The correct key was %d.\n", correctKey);
    return 0;
}
