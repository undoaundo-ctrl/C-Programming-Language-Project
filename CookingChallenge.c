#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const char *ingredients[6] = {"flour", "sugar", "eggs", "butter", "milk", "vanilla"};
    int needed[6], have[6] = {0}, i, item, correct = 1;

    srand((unsigned int) time(NULL));
    printf("=== Cooking Challenge ===\nGather the right ingredients for the recipe!\n");

    for (i = 0; i < 6; i++) needed[i] = rand() % 2;

    printf("Recipe needs: ");
    for (i = 0; i < 6; i++) if (needed[i]) printf("%s ", ingredients[i]);
    printf("\n");

    printf("\nPick ingredients one at a time (0-5), -1 to finish: ");
    while (1) {
        if (scanf("%d", &item) != 1) break;
        if (item == -1) break;
        if (item < 0 || item > 5) { printf("Invalid.\n"); continue; }
        have[item] = 1;
        printf("Added %s.\n", ingredients[item]);
    }

    for (i = 0; i < 6; i++) if (needed[i] != have[i]) correct = 0;

    if (correct) printf("\nPerfect recipe! Delicious!\n");
    else printf("\nHmm, something's off with the recipe.\n");

    return 0;
}
