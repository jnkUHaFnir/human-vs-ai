#include <stdio.h>
#include <string.h>

void formPlural(char *noun) {
    int len = strlen(noun);

    if (noun[len - 1] == 'y') {
        noun[len - 1] = '\0';
        strcat(noun, "ies");
    } else if (noun[len - 1] == 's' || 
                  (noun[len - 2] == 'c' && noun[len - 1] == 'h') || 
                  (noun[len - 2] == 's' && noun[len - 1] == 'h')) {
        strcat(noun, "es");
    } else {
        strcat(noun, "s");
    }
}

int main() {
    char nouns[][20] = { "chair", "dairy", "boss", "circus", "fly", "dog", "church", "clue", "dish" };

    for (int i = 0; i < sizeof(nouns) / sizeof(nouns[0]); i++) {
        char plural[20];
        strcpy(plural, nouns[i]);
        formPlural(plural);
        printf("%s -> %s\n", nouns[i], plural);
    }

    return 0;
}
