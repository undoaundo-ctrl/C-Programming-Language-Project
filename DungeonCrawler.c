#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerHP = 30, monsterHP = 25, choice, playerDmg, monsterDmg, round = 0;

    srand((unsigned int) time(NULL));
    printf("=== Dungeon Crawler ===\nA monster blocks your path! Fight or flee.\n");

    while (playerHP > 0 && monsterHP > 0) {
        round++;
        printf("\n-- Round %d --\n", round);
        printf("Your HP: %d | Monster HP: %d\n", playerHP, monsterHP);
        printf("1=Attack 2=Defend(reduce damage) 3=Run\n> ");
        if (scanf("%d", &choice) != 1) break;

        if (choice == 3) {
            if (rand() % 2 == 0) { printf("You escaped safely!\n"); return 0; }
            printf("Couldn't escape!\n");
        } else if (choice == 1) {
            playerDmg = 3 + rand() % 6;
            monsterHP -= playerDmg;
            printf("You strike for %d damage!\n", playerDmg);
        } else {
            printf("You brace for the monster's attack.\n");
        }

        if (monsterHP <= 0) { printf("\nThe monster is defeated! You win!\n"); return 0; }

        monsterDmg = 2 + rand() % 6;
        if (choice == 2) monsterDmg /= 2;
        playerHP -= monsterDmg;
        printf("The monster hits you for %d damage!\n", monsterDmg);

        if (playerHP <= 0) { printf("\nYou have fallen. Game over.\n"); return 0; }
    }

    return 0;
}
