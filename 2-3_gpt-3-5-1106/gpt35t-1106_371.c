#include <stdio.h>
#include <string.h>

void formPlural(char *noun)
{
    int length = strlen(noun);
    if (noun[length - 1] == 'y') {
        noun[length - 1] = '\0'; // remove the last character (y)
        strcat(noun, "ies");
    } else if (noun[length - 1] == 's' || (noun[length - 1] == 'h' && noun[length - 2] == 'c')) {
        strcat(noun, "es");
    } else {
        strcat(noun, "s");
    }
}

int main(void)
{
    char nouns[8][20] = {"chair", "dairy", "boss", "circus", "fly", "dog", "church", "clue", "dish"};
    char plural[20];

    for (int i = 0; i < 9; i++) {
        strcpy(plural, nouns[i]);
        formPlural(plural);
        printf("%s -> %s\n", nouns[i], plural);
    }

    return 0;
}
