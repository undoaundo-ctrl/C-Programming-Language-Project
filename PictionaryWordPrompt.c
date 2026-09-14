#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const char *words[20] = {
        "elephant", "bicycle", "rainbow", "castle", "pizza",
        "airplane", "guitar", "mountain", "robot", "umbrella",
        "dragon", "volcano", "spaceship", "penguin", "treasure",
        "lighthouse", "waterfall", "dinosaur", "campfire", "telescope"
    };
    const char *categories[4] = {"Animal", "Object", "Place", "Action"};
    int wordIndex, catIndex;
    char again;

    srand((unsigned int) time(NULL));
    printf("=== Pictionary Word Prompt ===\nGet a random word and category to draw!\n");

    do {
        wordIndex = rand() % 20;
        catIndex = rand() % 4;

        printf("\nCategory: %s\nDraw: %s\n", categories[catIndex], words[wordIndex]);
        printf("\nNew prompt? (y/n): ");
        scanf(" %c", &again);
    } while (again == 'y' || again == 'Y');

    printf("Thanks for playing!\n");
    return 0;
}
