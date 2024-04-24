#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 20

// function to pluralize a noun
void pluralize(char noun[])
{
    int length = strlen(noun);
    bool add_s = true; // assume we'll add "s" by default

    // check for exceptions
    if (noun[length-1] == 'y') {
        noun[length-1] = 'i';
        strcat(noun, "es");
        add_s = false;
    }
    else if (noun[length-1] == 's' || 
             (noun[length-2] == 'c' && noun[length-1] == 'h') ||
             (noun[length-2] == 's' && noun[length-1] == 'h')) {
        strcat(noun, "es");
        add_s = false;
    }

    // add "s" if necessary
    if (add_s) {
        strcat(noun, "s");
    }
}

int main(void)
{
    char nouns[][SIZE] = {"chair", "dairy", "boss", "circus", "fly", 
                           "dog", "church", "clue", "dish"};
    int count = sizeof(nouns) / sizeof(nouns[0]);

    for (int i = 0; i < count; i++) {
        char plural[SIZE];
        strcpy(plural, nouns[i]);
        pluralize(plural);
        printf("%s -> %s\n", nouns[i], plural);
    }

    return 0;
}
