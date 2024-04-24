#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 100

char *get_plural(char *noun) {
    static char plural[SIZE];

    if (noun[strlen(noun) - 1] == 'y') {
        strcpy(plural, noun);
        plural[strlen(plural) - 1] = '\0';
        strcat(plural, "ies");
    } else if (noun[strlen(noun) - 1] == 's' || 
               (noun[strlen(noun) - 2] == 'c' && noun[strlen(noun) - 1] == 'h') || 
               (noun[strlen(noun) - 2] == 's' && noun[strlen(noun) - 1] == 'h')) {
        strcpy(plural, noun);
        strcat(plural, "es");
    } else {
        strcpy(plural, noun);
        strcat(plural, "s");
    }

    return plural;
}

int main() {
    char nouns[SIZE][SIZE] = {"chair", "dairy", "boss", "circus", "fly", "dog", "church", "clue", "dish"};

    for (int i = 0; i < SIZE; i++) {
        printf("%s -> %s\n", nouns[i], get_plural(nouns[i]));
    }

    return 0;
}
