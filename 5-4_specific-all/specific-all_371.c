#include <stdio.h>
#include <string.h>

#define SIZE 20

void pluralizeNoun(char *noun) {
    if (noun[strlen(noun) - 1] == 'y') {
        noun[strlen(noun) - 1] = '\0'; // Remove 'y'
        strcat(noun, "ies"); // Add "ies"
    } else if (noun[strlen(noun) - 1] == 's' || 
               (noun[strlen(noun) - 1] == 'h' && noun[strlen(noun) - 2] == 'c') ||
               (noun[strlen(noun) - 1] == 'h' && noun[strlen(noun) - 2] == 's')) {
        strcat(noun, "es"); // Add "es"
    } else {
        strcat(noun, "s"); // Just add "s"
    }
}

int main() {
    char nouns[][SIZE] = {"chair", "dairy", "boss", "circus", "fly", "dog", "church", "clue", "dish"};

    for (int i = 0; i < 9; i++) {
        printf("%-10s -> ", nouns[i]);
        pluralizeNoun(nouns[i]);
        printf("%s\n", nouns[i]);
    }

    return 0;
}
