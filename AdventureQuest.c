#include <stdio.h>

int main() {
    int choice;

    printf("=== Adventure Quest ===\n");
    printf("You stand before a dark forest and a rocky cave.\n");
    printf("1. Enter the forest\n2. Enter the cave\n> ");
    if (scanf("%d", &choice) != 1) return 1;

    if (choice == 1) {
        printf("\nYou walk into the forest and find a fork in the path.\n");
        printf("1. Go left toward the light\n2. Go right into the darkness\n> ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("\nYou find a peaceful clearing with a treasure chest! You win!\n");
        } else {
            printf("\nA wolf ambushes you in the dark. Game over.\n");
        }
    } else if (choice == 2) {
        printf("\nInside the cave, you hear a growl.\n");
        printf("1. Fight the creature\n2. Run away\n> ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("\nYou bravely defeat the creature and find gold! You win!\n");
        } else {
            printf("\nYou escape safely, but leave empty-handed. The end.\n");
        }
    } else {
        printf("\nYou hesitate too long and the sun sets. The end.\n");
    }

    return 0;
}
