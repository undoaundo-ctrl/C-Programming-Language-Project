#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_WRONG 6
#define WORD_COUNT 8

void printHangman(int wrong) {
    printf("\nAttempts left: %d\n", MAX_WRONG - wrong);
}

int main() {
    const char *words[WORD_COUNT] = {
        "programming", "computer", "keyboard", "hangman",
        "developer", "function", "variable", "compiler"
    };
    char word[50];
    char guessed[50];
    char letter;
    int wordLen, wrongGuesses = 0, guessedCount = 0, i, found;
    int alreadyGuessed[26] = {0};

    srand((unsigned int) time(NULL));
    strcpy(word, words[rand() % WORD_COUNT]);
    wordLen = (int) strlen(word);

    for (i = 0; i < wordLen; i++) guessed[i] = '_';
    guessed[wordLen] = '\0';

    printf("=== Hangman ===\n");

    while (wrongGuesses < MAX_WRONG && guessedCount < wordLen) {
        printf("\nWord: %s\n", guessed);
        printHangman(wrongGuesses);
        printf("Guess a letter: ");
        scanf(" %c", &letter);
        letter = (char) tolower((unsigned char) letter);

        if (letter < 'a' || letter > 'z') {
            printf("Please enter a valid letter.\n");
            continue;
        }

        if (alreadyGuessed[letter - 'a']) {
            printf("You already guessed that letter.\n");
            continue;
        }
        alreadyGuessed[letter - 'a'] = 1;

        found = 0;
        for (i = 0; i < wordLen; i++) {
            if (word[i] == letter && guessed[i] == '_') {
                guessed[i] = letter;
                guessedCount++;
                found = 1;
            }
        }

        if (!found) {
            wrongGuesses++;
            printf("Wrong! '%c' is not in the word.\n", letter);
        } else {
            printf("Good guess!\n");
        }
    }

    if (guessedCount == wordLen) {
        printf("\nYou guessed it! The word was: %s\n", word);
    } else {
        printf("\nOut of attempts! The word was: %s\n", word);
    }

    return 0;
}
