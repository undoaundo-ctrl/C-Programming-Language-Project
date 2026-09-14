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
    srand((unsigned)time(NULL));

    print_banner();
    print_rules();

    int total = 0;
    int human_turn;

    printf("Would you like to go first? (y/n): ");
    char first;
    scanf(" %c", &first);
    human_turn = (first == 'y' || first == 'Y');

    while (total < TARGET) {
        int move;

        if (human_turn) {
            move = get_human_move(total);
            printf("You added %d. ", move);
        } else {
            move = get_computer_move(total);
            printf("Computer added %d. ", move);
        }

        total += move;
        printf("Total is now %d.\n", total);

        if (total >= TARGET) {
            if (human_turn) {
                printf("\nCongratulations! You reached %d and won!\n", TARGET);
            } else {
                printf("\nThe computer reached %d and won. Better luck next time!\n", TARGET);
            }
            break;
        }

        human_turn = !human_turn;
    }

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

int get_human_move(int total) {
    int remaining = TARGET - total;
    int hi = (remaining < MAX_MOVE) ? remaining : MAX_MOVE;

    printf("Current total: %d. Choose a number between %d and %d: ", total, MIN_MOVE, hi);
    return read_int_in_range(MIN_MOVE, hi);
}

int get_computer_move(int total) {
    int remaining = TARGET - total;
    int hi = (remaining < MAX_MOVE) ? remaining : MAX_MOVE;
    int move;

    /* Optimal strategy: try to leave the total as a multiple of 11. */
    int ideal = (total % 11 == 0) ? MAX_MOVE : (11 - (total % 11));

    if (ideal >= MIN_MOVE && ideal <= hi) {
        move = ideal;
    } else {
        move = (rand() % hi) + 1;
    }

    return move;
}
