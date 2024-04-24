#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void pluralize_noun(char *noun) {
    int len = strlen(noun);
    
    if (len >= 1 && noun[len - 1] == 'y') {
        noun[len - 1] = '\0'; // remove 'y'
        strcat(noun, "ies"); // add 'ies'
    } else if ((len >= 2 && strcmp(noun + len - 2, "sh") == 0)
            || (len >= 2 && strcmp(noun + len - 2, "ch") == 0)
            || (len >= 1 && noun[len - 1] == 's')) {
        strcat(noun, "es"); // add 'es'
    } else {
        strcat(noun, "s"); // add 's'
    }
}

int main(void) {
    // Nouns to test
    char nouns[8][20] = {
        "chair", "dairy", "boss", "circus", 
        "fly", "dog", "church", "clue"
    };
    
    for (int i = 0; i < 8; i++) {
        char plural[20];
        strcpy(plural, nouns[i]);
        pluralize_noun(plural);
        
        printf("%s -> %s\n", nouns[i], plural);
    }
    
    return 0;
}
