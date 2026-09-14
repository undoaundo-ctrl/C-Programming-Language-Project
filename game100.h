#ifndef GAME100_H
#define GAME100_H

#define TARGET      100
#define MIN_MOVE    1
#define MAX_MOVE    10

void print_banner(void);
void print_rules(void);
int  get_human_move(int total);
int  get_computer_move(int total);
int  read_int_in_range(int lo, int hi);

#endif /* GAME100_H */
