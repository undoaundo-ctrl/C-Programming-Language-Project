#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    int frame = 0;

    while (1) {
        printf("\033[2J\033[H");

        printf("\033[1;33m                 *\033[0m\n");
        printf("\033[1;32m                /\\\033[0m\n");
        printf("\033[1;32m               /  \\\033[0m\n");
        printf("\033[1;32m              /    \\\033[0m\n");
        printf("\033[1;32m             /");
        printf(frame % 2 ? "\033[1;31m o " : "\033[1;34m o ");
        printf("\033[1;32m  \\\033[0m\n");

        printf("\033[1;32m            /  ");
        printf(frame % 3 ? "\033[1;33m* " : "\033[1;35m* ");
        printf("  o   \\\033[0m\n");

        printf("\033[1;32m           /");
        printf(frame % 2 ? "\033[1;35m o  " : "\033[1;36m o  ");
        printf("\033[1;32m  *   \\\033[0m\n");

        printf("\033[1;32m          /   o    *   \\\033[0m\n");

        printf("\033[1;32m         /");
        printf(frame % 2 ? "\033[1;31m * " : "\033[1;34m * ");
        printf(" o   ");
        printf(frame % 3 ? "\033[1;33m o " : "\033[1;35m o ");
        printf("  \\\033[0m\n");

        printf("\033[1;32m        /   o    *    o   \\\033[0m\n");

        printf("\033[1;32m       /");
        printf(frame % 2 ? "\033[1;34m o " : "\033[1;31m o ");
        printf("   *    ");
        printf(frame % 3 ? "\033[1;36m o " : "\033[1;33m o ");
        printf("  *  \\\033[0m\n");

        printf("\033[1;32m      /   *    o    *    o   \\\033[0m\n");

        printf("\033[1;32m     /");
        printf(frame % 2 ? "\033[1;35m o " : "\033[1;33m o ");
        printf("  *   o   ");
        printf(frame % 3 ? "\033[1;31m * " : "\033[1;34m * ");
        printf("   o  \\\033[0m\n");

        printf("\033[1;32m    /________________________________\\\033[0m\n");

        printf("\033[1;33m              ||||\033[0m\n");
        printf("\033[1;33m              ||||\033[0m\n");
        printf("\033[1;33m             _||||_\033[0m\n");

        fflush(stdout);

        usleep(300000);
        frame++;
    }

    return 0;
}
