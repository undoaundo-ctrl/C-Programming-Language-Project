#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int money = 20, day, price, cupsSold, cost, days = 7;
    double demandFactor;

    srand((unsigned int) time(NULL));
    printf("=== Lemonade Stand ===\nYou start with $%d. Run your stand for %d days.\n", money, days);

    for (day = 1; day <= days; day++) {
        printf("\n-- Day %d -- Money: $%d\n", day, money);
        printf("Set price per cup (in cents, e.g. 50): ");
        if (scanf("%d", &price) != 1) break;

        cost = 20;
        if (money < cost) { printf("Not enough money to make supplies!\n"); break; }
        money -= cost;

        demandFactor = 100.0 / (price > 0 ? price : 1);
        cupsSold = (int) (demandFactor * (5 + rand() % 10));
        if (cupsSold > 50) cupsSold = 50;

        printf("You sold %d cups at %d cents each!\n", cupsSold, price);
        money += (cupsSold * price) / 100;
        printf("End of day money: $%d\n", money);
    }

    printf("\nFinal money after %d days: $%d\n", days, money);
    return 0;
}
