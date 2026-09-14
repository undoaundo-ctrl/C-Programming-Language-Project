#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20

int main() {
    int ballPos, direction, playerScore = 0, computerScore = 0, choice;
    int rounds = 5, i, r;

    srand((unsigned int) time(NULL));
    printf("=== Pong (text, turn-based) ===\nPredict where the ball will land: left(0) or right(1) half.\n");

    for (r = 1; r <= rounds; r++) {
        direction = (rand() % 2 == 0) ? -1 : 1;
        printf("\nRound %d - Ball is launching. Predict landing half (0=left, 1=right): ", r);
        if (scanf("%d", &choice) != 1) continue;

        ballPos = WIDTH / 2;
        for (i = 0; i < WIDTH / 2; i++) ballPos += direction;

        {
            int landedRight = (ballPos > WIDTH / 2);
            if ((choice == 1 && landedRight) || (choice == 0 && !landedRight)) {
                printf("Correct! Ball landed on the %s.\n", landedRight ? "right" : "left");
                playerScore++;
            } else {
                printf("Wrong! Ball landed on the %s.\n", landedRight ? "right" : "left");
                computerScore++;
            }
        }
    }

    printf("\nFinal - You: %d, Computer: %d\n", playerScore, computerScore);
    return 0;
}
