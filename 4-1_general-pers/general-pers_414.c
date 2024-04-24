#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Person {
    char *name;
    char *surname;
    char *address;
    char *number;
} Person;

char *getString(void);

int main(void) {
    struct Person *rub = NULL;
    int idx = 0;
    char c;
    
    do {
        // Your menu and input handling here
        
        switch (c) {
            case 'i':
                // Memory allocation and reading strings
                // ...
                rub[idx].name = (char *) malloc(strlen(tmp) + 1);
                strcpy(rub[idx].name, tmp);

                // Similar changes for other struct members
            case 'p':
                // Print list here
                // ...
        }
        
        // Other menu options
        
    } while (c != '0');

    // Free allocated memory before exiting
    for (int i = 0; i < idx; i++) {
        free(rub[i].name);
        free(rub[i].surname);
        free(rub[i].address);
        free(rub[i].number);
    }
    free(rub);

    return 0;
}

char *getString(void) {
    char *stringa = NULL, c;
    int i = 0;
    
    stringa = malloc(sizeof(char));
    while ((c = getchar()) != '\n') {
        stringa = (char *)realloc(stringa, (i + 1) * sizeof(char));
        stringa[i++] = c;
    }
    stringa[i] = '\0';
    return stringa;
}
