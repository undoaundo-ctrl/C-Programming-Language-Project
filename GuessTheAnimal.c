#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ANIMALS 6

int namesMatch(const char *a, const char *b) {
    while (*a && *b) {
        char ca = (*a >= 'A' && *a <= 'Z') ? (char) (*a + 32) : *a;
        char cb = (*b >= 'A' && *b <= 'Z') ? (char) (*b + 32) : *b;
        if (ca != cb) return 0;
        a++; b++;
    }
    return *a == '\0' && *b == '\0';
}

int main() {
    const char *animals[NUM_ANIMALS] = {"Elephant", "Giraffe", "Penguin", "Kangaroo", "Dolphin", "Cheetah"};
    const char *hints[NUM_ANIMALS] = {
        "I am the largest land animal with a trunk.",
        "I have the longest neck of any animal.",
        "I am a flightless bird that loves cold water.",
        "I carry my baby in a pouch.",
        "I am a smart marine mammal known for clicking sounds.",
        "I am the fastest land animal."
    };
    int index, guessed = 0, tries = 0;
    char guess[50];

    srand((unsigned int) time(NULL));
    index = rand() % NUM_ANIMALS;

    printf("=== Guess the Animal ===\n");
    printf("%s\n", hints[index]);

    while (!guessed && tries < 3) {
        tries++;
        printf("Your guess: ");
        scanf("%49s", guess);

        if (namesMatch(guess, animals[index])) { guessed = 1; }
        else printf("Not quite, try again.\n");
    }

    if (guessed) printf("\nCorrect! It was the %s!\n", animals[index]);
    else printf("\nOut of tries! It was the %s.\n", animals[index]);

    return 0;
}
