#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int food = 10, water = 10, days = 0, choice;

    srand((unsigned int) time(NULL));
    printf("=== Survival Countdown ===\nManage food and water to survive as long as possible.\n");

    while (food > 0 && water > 0) {
        days++;
        printf("\nDay %d - Food: %d, Water: %d\n", days, food, water);
        printf("1=Forage for food 2=Search for water 3=Rest: ");
        if (scanf("%d", &choice) != 1) break;

        if (choice == 1) { food += 1 + rand() % 3; printf("Found some food!\n"); }
        else if (choice == 2) { water += 1 + rand() % 3; printf("Found some water!\n"); }
        else printf("You rest.\n");

        food--;
        water--;
        if (food < 0) food = 0;
        if (water < 0) water = 0;
    }

    printf("\nYou survived %d days!\n", days);
    return 0;
}
