#include <stdio.h>

#define NUM_QUESTIONS 5

int main() {
    const char *questions[NUM_QUESTIONS] = {
        "What does CPU stand for?\n1. Central Process Unit\n2. Central Processing Unit\n3. Computer Personal Unit\n4. Central Processor Utility",
        "Which language is this program written in?\n1. Python\n2. Java\n3. C\n4. Ruby",
        "What is 2 + 2 * 2?\n1. 8\n2. 6\n3. 4\n4. 2",
        "Which symbol is used for single-line comments in C99 and later?\n1. #\n2. //\n3. --\n4. <!--",
        "What does 'int' stand for in C?\n1. Internal\n2. Integer\n3. Interface\n4. Integral"
    };
    int answers[NUM_QUESTIONS] = {2, 3, 2, 2, 2};
    int score = 0, choice, i;

    printf("=== C Programming Quiz ===\n");
    printf("Answer each question by entering the number (1-4).\n");

    for (i = 0; i < NUM_QUESTIONS; i++) {
        printf("\nQuestion %d:\n%s\n", i + 1, questions[i]);
        printf("Your answer: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input, skipping question.\n");
            continue;
        }

        if (choice == answers[i]) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct answer was %d.\n", answers[i]);
        }
    }

    printf("\n=== Quiz Complete ===\n");
    printf("You scored %d out of %d.\n", score, NUM_QUESTIONS);

    if (score == NUM_QUESTIONS) printf("Perfect score!\n");
    else if (score >= NUM_QUESTIONS / 2) printf("Good job!\n");
    else printf("Keep practicing!\n");

    return 0;
}
