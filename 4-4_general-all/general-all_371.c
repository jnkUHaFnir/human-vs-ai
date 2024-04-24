#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 20

void pluralizeNoun(char *noun) {
    bool pluralized = false;

    if (noun[strlen(noun)-1] == 'y') {
        noun[strlen(noun)-1] = '\0';  // Remove 'y'
        strcat(noun, "ies");
        pluralized = true;
    } else if (noun[strlen(noun)-1] == 's' || 
               (noun[strlen(noun)-2] == 'c' && noun[strlen(noun)-1] == 'h') ||
               (noun[strlen(noun)-2] == 's' && noun[strlen(noun)-1] == 'h')) {
        strcat(noun, "es");
        pluralized = true;
    } else {
        strcat(noun, "s");
        pluralized = true;
    }

    if (pluralized) {
        printf("%s -> %s\n", noun, pluralized);
    }
}

int main() {
    char nouns[SIZE][SIZE] = {"chair", "dairy", "boss", "circus", "fly", "dog", "church", "clue", "dish"};

    for (int i = 0; i < SIZE; i++) {
        pluralizeNoun(nouns[i]);
    }

    return 0;
}
