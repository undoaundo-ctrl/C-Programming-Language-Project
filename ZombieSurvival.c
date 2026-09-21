#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int health = 100, ammo = 10, zombies = 5, choice, damage;

    srand((unsigned int) time(NULL));
    printf("=== Zombie Survival ===\nSurvive the horde! Health: %d, Ammo: %d, Zombies: %d\n", health, ammo, zombies);

    while (health > 0 && zombies > 0) {
        printf("\nHealth: %d | Ammo: %d | Zombies left: %d\n", health, ammo, zombies);
        printf("1=Shoot 2=Melee 3=Barricade(heal a bit): ");
        if (scanf("%d", &choice) != 1) break;

        if (choice == 1 && ammo > 0) {
            ammo--;
            if (rand() % 4 != 0) { zombies--; printf("Direct hit! Zombie down.\n"); }
            else printf("Missed!\n");
        } else if (choice == 2) {
            if (rand() % 2 == 0) { zombies--; printf("Melee kill!\n"); }
            else { damage = 5 + rand() % 10; health -= damage; printf("Zombie clawed you for %d damage!\n", damage); }
        } else if (choice == 3) {
            health += 5;
            if (health > 100) health = 100;
            printf("You barricade and recover a bit.\n");
        } else {
            printf("Invalid or out of ammo!\n");
            continue;
        }

        if (zombies > 0) {
            damage = rand() % 8;
            if (damage > 0) { health -= damage; printf("A zombie attacks you for %d damage!\n", damage); }
        }
    }

    if (health <= 0) printf("\nYou were overrun. Game over.\n");
    else printf("\nAll zombies defeated! You survived!\n");

    return 0;
}
