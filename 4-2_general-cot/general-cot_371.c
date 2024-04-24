#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void pluralizeNoun(char *noun) {
    char plural[20]; // Make sure the array is large enough to hold plural forms
    strcpy(plural, noun); // Copy the noun to plural to start with the original noun

    int length = strlen(noun);
    bool pluralized = false; // Flag to check if noun has been pluralized

    if (noun[length - 1] == 'y') {
        plural[length - 1] = '\0'; // Replace 'y' with null terminator
        strcat(plural, "ies");
        pluralized = true;
    } else if (noun[length - 1] == 's' || (noun[length - 1] == 'h' && (noun[length - 2] == 'c' || noun[length - 2] == 's'))) {
        strcat(plural, "es");
        pluralized = true;
    } else {
        strcat(plural, "s");
        pluralized = true;
    }

    if (pluralized) {
        printf("%s -> %s\n", noun, plural);
    }
}

int main() {
    char nouns[8][20] = {"chair", "dairy", "boss", "circus", "fly", "dog", "church", "clue", "dish"};
    for (int i = 0; i < 9; i++) {
        pluralizeNoun(nouns[i]);
    }

    return 0;
}
