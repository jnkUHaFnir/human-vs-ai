#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 100 // This should be large enough to hold noun strings

void make_plural(char *noun, char *plural) {
    // Check if noun ends in "y"
    int len = strlen(noun);
    if (noun[len - 1] == 'y') {
        strcpy(plural, noun);
        plural[len - 1] = '\0'; // Remove the last character 'y'
        strcat(plural, "ies"); // Add 'ies' to the end
    }
    // Check if noun ends in "s", "ch", or "sh"
    else if (noun[len - 1] == 's' ||
             (len > 1 && noun[len - 2] == 'c' && noun[len - 1] == 'h') ||
             (len > 1 && noun[len - 2] == 's' && noun[len - 1] == 'h')) {
        strcpy(plural, noun);
        strcat(plural, "es"); // Add 'es' to the end
    }
    // For all other cases, just add 's'
    else {
        strcpy(plural, noun);
        strcat(plural, "s"); // Add 's' to the end
    }
}

int main(void) {
    char *nouns[] = {"chair", "dairy", "boss", "circus", "fly", "dog", "church", "clue", "dish"};
    size_t count = sizeof(nouns) / sizeof(char*);
    char plural[SIZE];

    for (size_t i = 0; i < count; ++i) {
        make_plural(nouns[i], plural);
        printf("Singular: %s - Plural: %s\n", nouns[i], plural);
    }

    return 0;
}
