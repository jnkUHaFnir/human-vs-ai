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
    Person *rub = NULL, *ttmp = NULL;
    int idx = 0;
    char c;
    char *tmp = NULL;

    do {
        printf("*******************************\ni - Insert new\nn - Find by name\nc - Find by surname\ne - Delete\np - Print list\n0 - Exit\n*******************************\n");
        c = getchar();
        fflush(stdin);

        switch (c) {
            case 'i':
                ttmp = (Person *)realloc(rub, (idx + 1) * sizeof(Person));
                if (ttmp == NULL) {
                    printf("Cannot allocate more memory.\n");
                    exit(1);
                }
                rub = ttmp;

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
                for (int k = 0; k < idx; k++) {
                    printf("%d) %s %s\n%s\n%s\n-------------------\n", k + 1, rub[k].name, rub[k].surname, rub[k].address, rub[k].number);
                }
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

            case 'c':
                printf("What surname are you looking for? ");
                scanf("%s", tmp);
                for (int k = 0; k < idx; k++) {
                    if (strcmp(rub[k].surname, tmp) == 0) {
                        printf("%s\n%s\n%s\n%s\n", rub[k].name, rub[k].surname, rub[k].address, rub[k].number);
                    }
                }
                break;

            case 'e':
                printf("Select number to delete record: ");
                int j;
                scanf("%d", &j);

                if (j > 0 && j <= idx) {
                    ttmp = (Person *)malloc((idx - 1) * sizeof(Person));
                    for (int k = 0, i = 0; k < idx; k++) {
                        if (k != j - 1) {
                            ttmp[i] = rub[k];
                            i++;
                        }
                    }

                    idx--;
                    free(rub);
                    rub = ttmp;
                } else {
                    printf("Invalid record number!\n");
                }

                for (int k = 0; k < idx; k++) {
                    printf("%d/%d) %s %s\n%s\n%s\n-------------------\n", k, idx, rub[k].name, rub[k].surname, rub[k].address, rub[k].number);
                }
                break;

            case 'p':
                for (int k = 0; k < idx; k++) {
                    printf("%d) %s %s\n%s\n%s\n-------------------\n", k + 1, rub[k].name,rub[k].surname,rub[k].address,rub[k].number);
                }
                break;

            case '0':
                return 0;
        }

    } while (c != '0');

    return 0;
}

char *getString(void) {
    char *stringa = NULL;
    int i = 0;
    char c;

    stringa = (char *)malloc(1);
    while ((c = getchar()) != '\n' && c != EOF) {
        stringa = (char *)realloc(stringa, (i + 2) * sizeof(char));
        stringa[i++] = c;
        stringa[i] = '\0';
    }

    return stringa;
}
