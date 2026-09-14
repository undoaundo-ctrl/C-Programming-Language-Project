#include <stdio.h>

int peg[3][20];
int pegTop[3];
int numDisks;

void printPegs() {
    int i, j;
    printf("\n");
    for (i = 0; i < 3; i++) {
        printf("Peg %c: ", 'A' + i);
        for (j = 0; j < pegTop[i]; j++) printf("%d ", peg[i][j]);
        printf("\n");
    }
}

int main() {
    int from, to, moves = 0, minMoves;
    int diskToMove;

    printf("=== Tower of Hanoi ===\n");
    printf("How many disks (1-10)? ");
    if (scanf("%d", &numDisks) != 1 || numDisks < 1 || numDisks > 10) {
        printf("Invalid number.\n");
        return 1;
    }

    for (diskToMove = numDisks; diskToMove >= 1; diskToMove--) {
        peg[0][pegTop[0]++] = diskToMove;
    }

    minMoves = (1 << numDisks) - 1;
    printf("Move all disks from Peg A to Peg C. Minimum moves: %d\n", minMoves);
    printf("Enter pegs as numbers: 0=A, 1=B, 2=C\n");

    while (pegTop[2] != numDisks) {
        printPegs();
        printf("Move from peg: ");
        if (scanf("%d", &from) != 1 || from < 0 || from > 2) { printf("Invalid.\n"); continue; }
        printf("Move to peg: ");
        if (scanf("%d", &to) != 1 || to < 0 || to > 2) { printf("Invalid.\n"); continue; }

        if (pegTop[from] == 0) { printf("That peg is empty.\n"); continue; }

        diskToMove = peg[from][pegTop[from] - 1];
        if (pegTop[to] > 0 && peg[to][pegTop[to] - 1] < diskToMove) {
            printf("Can't place a bigger disk on a smaller one.\n");
            continue;
        }

        pegTop[from]--;
        peg[to][pegTop[to]++] = diskToMove;
        moves++;
    }

    printPegs();
    printf("\nSolved in %d moves! (Minimum was %d)\n", moves, minMoves);
    return 0;
}
