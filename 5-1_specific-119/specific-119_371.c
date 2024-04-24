#include <stdio.h>
#include <string.h>

void replace_plural(char *noun) {
    char plural[50];
    strcpy(plural, noun);

    int length = strlen(plural);

    // Rule 1: If noun ends in "y", remove the "y" and add "ies"
    if (plural[length-1] == 'y') {
        plural[length-1] = '\0';
        strcat(plural, "ies");
    }
    // Rule 2: If noun ends in "s", "ch", or "sh", add "es"
    else if (plural[length-1] == 's' || 
             (plural[length-1] == 'h' && (plural[length-2] == 'c' || plural[length-2] == 's'))) {
        strcat(plural, "es");
    }
    // Rule 3: In all other cases, just add "s"
    else {
        strcat(plural, "s");
    }

    printf("%s -> %s\n", noun, plural);
}

int main(void) {
    char nouns[][50] = {"chair", "dairy", "boss", "circus", "fly", "dog", "church", "clue", "dish"};
    int num_nouns = sizeof(nouns) / sizeof(nouns[0]);

    for (int i = 0; i < num_nouns; i++) {
        replace_plural(nouns[i]);
    }

    return 0;
}
