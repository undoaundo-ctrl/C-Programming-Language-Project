#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {
    while (1) {
        time_t now = time(NULL) + 3 * 60 * 60;
        struct tm *t = gmtime(&now);

        printf("\rMoscow: %02d:%02d:%02d",
               t->tm_hour, t->tm_min, t->tm_sec);

        fflush(stdout);
        sleep(1);
    }

    return 0;
}
