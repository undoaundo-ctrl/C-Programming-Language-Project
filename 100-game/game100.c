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
    printf("Welcome to the 100 Game! (work in progress)\n");
    return 0;
}
