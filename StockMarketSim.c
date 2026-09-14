#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    double price = 100.0, cash = 1000.0;
    int shares = 0, day, days = 10, action, qty;
    double change;

    srand((unsigned int) time(NULL));
    printf("=== Stock Market Simulator ===\nYou start with $%.2f. Trade over %d days.\n", cash, days);

    for (day = 1; day <= days; day++) {
        printf("\n-- Day %d -- Price: $%.2f | Cash: $%.2f | Shares: %d\n", day, price, cash, shares);
        printf("1=Buy 2=Sell 3=Hold: ");
        if (scanf("%d", &action) != 1) break;

        if (action == 1) {
            printf("How many shares to buy? ");
            scanf("%d", &qty);
            if (qty * price <= cash) { cash -= qty * price; shares += qty; printf("Bought %d shares.\n", qty); }
            else printf("Not enough cash.\n");
        } else if (action == 2) {
            printf("How many shares to sell? ");
            scanf("%d", &qty);
            if (qty <= shares) { cash += qty * price; shares -= qty; printf("Sold %d shares.\n", qty); }
            else printf("You don't have that many shares.\n");
        }

        change = ((rand() % 2000) - 1000) / 100.0;
        price += change;
        if (price < 1) price = 1;
        printf("Price changed by $%.2f\n", change);
    }

    printf("\nFinal - Cash: $%.2f, Shares: %d, Stock price: $%.2f\n", cash, shares, price);
    printf("Total net worth: $%.2f\n", cash + shares * price);

    return 0;
}
