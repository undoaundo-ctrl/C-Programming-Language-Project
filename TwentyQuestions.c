#include <stdio.h>

int main() {
    int a;

    printf("=== 20 Questions: Guess the Animal ===\nThink of an animal, I'll try to guess it!\n");

    printf("Does it live in water? (1=yes, 0=no): ");
    scanf("%d", &a);

    if (a == 1) {
        printf("Is it a mammal? (1=yes, 0=no): ");
        scanf("%d", &a);
        if (a == 1) printf("\nIs it a Dolphin?\n");
        else printf("\nIs it a Fish?\n");
    } else {
        printf("Can it fly? (1=yes, 0=no): ");
        scanf("%d", &a);
        if (a == 1) printf("\nIs it a Bird?\n");
        else {
            printf("Is it domesticated? (1=yes, 0=no): ");
            scanf("%d", &a);
            if (a == 1) printf("\nIs it a Dog or Cat?\n");
            else printf("\nIs it a Lion?\n");
        }
    }

    printf("Was I right? Thanks for playing!\n");
    return 0;
}
