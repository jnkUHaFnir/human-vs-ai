#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 100

// This function will return the plural form of the given noun
char *plural_form(char *noun) {
    static char plural[SIZE];
    int noun_len = strlen(noun);

    // Rule (a): If noun ends in "y" remove the "y" and add "ies"
    if (noun[noun_len - 1] == 'y') {
        strncpy(plural, noun, noun_len - 1);
        strcat(plural, "ies");
    }
    // Rule (b): If noun ends in “s”, “ch”, or “sh”, add "es"
    else if (noun[noun_len - 1] == 's' || (noun[noun_len - 2] == 'c' && noun[noun_len - 1] == 'h') || (noun[noun_len - 2] == 's' && noun[noun_len - 1] == 'h')) {
        strcpy(plural, noun);
        strcat(plural, "es");
    }
    // Rule (c): In all other cases, just add “s”
    else {
        strcpy(plural, noun);
        strcat(plural, "s");
    }

    return plural;
}

int main(void) {
    char noun[SIZE];

    printf("Enter a noun: ");
    scanf("%s", noun);

    printf("The plural form is: %s", plural_form(noun));

    return 0;
}
