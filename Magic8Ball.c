#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    const char *answers[10] = {
        "It is certain.", "Without a doubt.", "Yes, definitely.",
        "You may rely on it.", "Ask again later.", "Cannot predict now.",
        "Don't count on it.", "My reply is no.", "Very doubtful.",
        "Outlook not so good."
    };
    char question[200];
    char again;

    srand((unsigned int) time(NULL));
    printf("=== Magic 8-Ball ===\n");

    do {
        printf("\nAsk a yes/no question: ");
        getchar();
        fgets(question, sizeof(question), stdin);
        printf("The Magic 8-Ball says: %s\n", answers[rand() % 10]);

        printf("Ask again? (y/n): ");
        scanf(" %c", &again);
    } while (again == 'y' || again == 'Y');

    printf("Goodbye!\n");
    return 0;
}
