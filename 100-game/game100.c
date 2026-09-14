/*
 * 100 Game (Race to 100)
 * ------------------------
 * Two players take turns adding a number between 1 and 10 to a running
 * total. The player who makes the total reach exactly 100 wins.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TARGET      100
#define MIN_MOVE    1
#define MAX_MOVE    10

void print_banner(void);
void print_rules(void);
int  get_human_move(int total);
int  get_computer_move(int total);
int  read_int_in_range(int lo, int hi);

int main(void) {
    print_banner();
    print_rules();
    return 0;
}

void print_banner(void) {
    printf("=====================================\n");
    printf("           THE 100 GAME\n");
    printf("=====================================\n\n");
}

void print_rules(void) {
    printf("Rules:\n");
    printf(" - Players take turns adding a number from %d to %d to a running total.\n", MIN_MOVE, MAX_MOVE);
    printf(" - The player who makes the total reach exactly %d wins.\n\n", TARGET);
}

int read_int_in_range(int lo, int hi) {
    int value;
    int ok;

    do {
        ok = scanf("%d", &value);
        if (ok != 1) {
            while (getchar() != '\n');
            printf("Please enter a valid number: ");
            continue;
        }
        if (value < lo || value > hi) {
            printf("Please enter a number between %d and %d: ", lo, hi);
            ok = 0;
        }
    } while (!ok);

    return value;
}
