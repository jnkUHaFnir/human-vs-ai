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
    Person *rub = NULL;
    int idx = 0;
    char c;
    char *tmp = NULL;

    do {
        printf("*******************************\n");
        printf("i - Insert new\n");
        printf("n - Find by name\n");
        printf("c - Find by surname\n");
        printf("e - Delete\n");
        printf("p - Print list\n");
        printf("0 - Exit\n");
        printf("*******************************\n");
        c = getchar();
        getchar(); // to consume the newline
        printf("%c\n", c);

        switch (c) {
            case 'i':
                rub = (Person *) realloc(rub, (idx + 1) * sizeof(Person));
                if (rub == NULL) {
                    printf("Cannot allocate more memory.\n");
                    exit(1);
                }
                
                printf("Nome: ");
                tmp = getString();
                rub[idx].name = strdup(tmp);
                
                printf("Surname: ");
                tmp = getString();
                rub[idx].surname = strdup(tmp);
                
                printf("Address: ");
                tmp = getString();
                rub[idx].address = strdup(tmp);
                
                printf("Number: ");
                tmp = getString();
                rub[idx].number = strdup(tmp);

                idx++;
                break;

            case 'n':
                printf("What name are you looking for? ");
                scanf("%s", tmp);
                for (int k = 0; k < idx; k++) {
                    if (strcmp(rub[k].name, tmp) == 0) {
                        printf("%s\n%s\n%s\n%s\n", rub[k].name, rub[k].surname, rub[k].address, rub[k].number);
                    }
                }
                break;

            // Other cases omitted for brevity

            case '0':
                free(rub); // Free the memory before exiting
                return 0;
            default:
                printf("Invalid option.\n");
        }
        fseek(stdin, 0, SEEK_END);

    } while (c != '0');

    return 0;
}

char *getString(void) {
    char *stringa = NULL;
    char c;
    int i = 0;
    
    stringa = malloc(sizeof(char));
    if (stringa == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    
    while ((c = getchar()) != '\n') {
        stringa = (char *) realloc(stringa, (i + 2) * sizeof(char));
        if (stringa == NULL) {
            printf("Memory reallocation failed.\n");
            exit(1);
        }
        stringa[i++] = c;
    }
    stringa[i] = '\0';
    
    return stringa;
}
