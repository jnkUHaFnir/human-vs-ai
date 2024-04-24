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
        while (getchar() != '\n'); // consume the newline character

        switch (c) {
            case 'i':
                rub = (Person *)realloc(rub, (idx + 1) * sizeof(Person));
                rub[idx].name = getString();
                rub[idx].surname = getString();
                rub[idx].address = getString();
                rub[idx].number = getString();
                idx++;
                break;

            case 'n':
                printf("What name are you looking for? ");
                tmp = getString();
                for (int k = 0; k < idx; k++) {
                    if (strcmp(rub[k].name, tmp) == 0) {
                        printf("%s\n%s\n%s\n%s\n", rub[k].name, rub[k].surname, rub[k].address, rub[k].number);
                    }
                }
                free(tmp);
                break;

            case 'p':
                for (int k = 0; k < idx; k++) {
                    printf("%d) %s %s\n%s\n%s\n-------------------\n", k + 1, rub[k].name, rub[k].surname, rub[k].address, rub[k].number);
                }
                break;

            case '0':
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
    } while (c != '0');

    return 0;
}

char *getString(void) {
    char *string = NULL;
    size_t len = 0;
    ssize_t read;

    printf("Enter string: ");
    read = getline(&string, &len, stdin);
    if (read == -1) {
        perror("Error reading input");
        exit(EXIT_FAILURE);
    }

    // Remove newline character from the end of the string
    string[strcspn(string, "\n")] = '\0';

    return string;
}
