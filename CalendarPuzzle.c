#include <stdio.h>

int main() {
    int day, month, year, y, m, d, k, j, dayOfWeek;
    const char *dayNames[7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    printf("=== Calendar Puzzle ===\nEnter a date and guess the day of the week!\n");
    printf("Day: ");
    if (scanf("%d", &day) != 1) return 1;
    printf("Month: ");
    if (scanf("%d", &month) != 1) return 1;
    printf("Year: ");
    if (scanf("%d", &year) != 1) return 1;

    m = month;
    y = year;
    if (m < 3) { m += 12; y -= 1; }
    d = day;
    k = y % 100;
    j = y / 100;
    dayOfWeek = (d + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

    printf("\nGuess the day of the week: ");
    {
        char guess[20];
        scanf("%19s", guess);
        printf("The actual day was: %s\n", dayNames[dayOfWeek]);
    }

    return 0;
}
