#include <stdio.h>
#include <string.h>

void pluralize(char *noun) {
    int len = strlen(noun);
    
    if (noun[len-1] == 'y') {
        noun[len-1] = '\0';  // remove 'y'
        printf("%sies\n", noun);
    } else if (noun[len-1] == 's' || 
               (noun[len-2] == 'c' && noun[len-1] == 'h') ||
               (noun[len-2] == 's' && noun[len-1] == 'h')) {
        printf("%ses\n", noun);
    } else {
        printf("%ss\n", noun);
    }
}

int main(void) {
    char nouns[][20] = {"chair", "dairy", "boss", "circus", "fly", "dog", "church", "clue", "dish"};
    
    for (int i = 0; i < sizeof(nouns) / sizeof(nouns[0]); i++) {
        pluralize(nouns[i]);
    }

    return 0;
}
