#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int money = 50, crops = 0, day, days = 7, choice;

    srand((unsigned int) time(NULL));
    printf("=== Farm Simulator ===\nYou start with $%d. Run your farm for %d days.\n", money, days);

    for (day = 1; day <= days; day++) {
        printf("\n-- Day %d -- Money: $%d, Crops: %d\n", day, money, crops);
        printf("1=Plant seeds($5) 2=Harvest 3=Sell crops($3 each): ");
        if (scanf("%d", &choice) != 1) break;

        if (choice == 1) {
            if (money >= 5) { money -= 5; printf("Planted seeds!\n"); }
            else printf("Not enough money!\n");
        } else if (choice == 2) {
            int yield = 1 + rand() % 5;
            crops += yield;
            printf("Harvested %d crops!\n", yield);
        } else if (choice == 3) {
            money += crops * 3;
            printf("Sold %d crops for $%d!\n", crops, crops * 3);
            crops = 0;
        }
    }

    printf("\nFinal - Money: $%d, Crops: %d\n", money, crops);
    return 0;
}
