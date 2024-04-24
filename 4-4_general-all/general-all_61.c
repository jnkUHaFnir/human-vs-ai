#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char *tmp = NULL;

    do {
        // Your menu code here...

        switch(c) {
            case 'i':
                rub = (struct Person *)realloc(rub, (idx + 1) * sizeof(Person));
                if (rub == NULL) {
                    printf("Cannot allocate more memory.\n");
                    exit(1);
                }

                printf("Nome: ");
                tmp = getString();
                rub[idx].name = (char *)malloc(strlen(tmp) + 1);
                strcpy(rub[idx].name, tmp);
                
                // Repeat the above process for surname, address, and number...
                
                idx++;
                break;

            // Other cases and functionalities...

        } // End of switch

    } while(c != '0');

    // Free allocated memory before exiting
    for (int k = 0; k < idx; k++) {
        free(rub[k].name);
        free(rub[k].surname);
        free(rub[k].address);
        free(rub[k].number);
    }
    free(rub);

    return 0;
}

char *getString(void) {
    char *stringa = NULL, c;
    int i = 0;
    stringa = malloc(sizeof(char));
    
    while ((c = getchar()) != '\n') {
        stringa = (char *)realloc(stringa, (i + 2) * sizeof(char));
        stringa[i++] = c;
    }
    
    stringa[i] = '\0';
    return stringa;
}
