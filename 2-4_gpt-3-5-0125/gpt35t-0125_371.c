#include <stdio.h>
#include <string.h>

void pluralize(char *noun, char *plural) {
    strcpy(plural, noun);

    int len = strlen(noun);
    if (noun[len-1] == 'y') {
        plural[len-1] = '\0';
        strcat(plural, "ies");
    } else if (noun[len-1] == 's' || 
               (noun[len-1] == 'h' && noun[len-2] == 'c') ||
               (noun[len-1] == 'h' && noun[len-2] == 's')) {
        strcat(plural, "es");
    } else {
        strcat(plural, "s");
    }
}

int main(void) {
    char nouns[8][20] = {"chair", "dairy", "boss", "circus", "fly", "dog", "church", "clue", "dish"};
    char plurals[8][20];

    for (int i = 0; i < 8; i++) {
        pluralize(nouns[i], plurals[i]);
        printf("%s -> %s\n", nouns[i], plurals[i]);
    }

    return 0;
}
