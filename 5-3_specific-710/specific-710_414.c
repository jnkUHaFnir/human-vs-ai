...

// Update this function to handle the correct memory allocation
char *getString(void);

int main(void) {
    struct Person *rub = NULL, *ttmp = NULL;
    int idx = 0, i, j, k;
    char c;
    char *tmp = NULL;
    do {
        printf("*******************************\ni - Insert new\n");
        printf("n - Find by name\n");
        printf("c - Find by surname\n");
        printf("e - Delete\n");
        printf("p - Print list\n");
        printf("0 - Exit\n*******************************\n");
        c = getchar();
        printf("%d\n", c);
        getchar();
        switch (c) {
            case 'i':
                ttmp = (struct Person *)realloc(rub, (idx + 1) * sizeof(Person));
                if (ttmp == NULL) {
                    printf("Cannot allocate more memory.\n");
                    exit(1);
                } else
                    rub = ttmp;
                printf("Nome: ");
                rub[idx].name = getString();
                printf("Surname: ");
                rub[idx].surname = getString();
                printf("Address: ");
                rub[idx].address = getString();
                printf("Number: ");
                rub[idx].number = getString();
                idx++;
                for (k = 0; k < idx; k++) {
                    printf("%d) %s %s\n%s\n%s\n-------------------\n", k + 1, rub[k].name, rub[k].surname, rub[k].address, rub[k].number);
                }
                break;
            ...
            // Rest of the cases remain unchanged
        }
        fseek(stdin, 0, SEEK_END);
    } while (c != '0');
    return 0;
}

char *getString(void) {
    char *stringa = NULL, c;
    int i = 0;
    stringa = malloc(sizeof(char));
    while ((c = getchar()) != '\n') {
        stringa = (char *)realloc(stringa, (i + 2) * sizeof(char));  // Increase the size by 2 to account for the new character and null terminator
        stringa[i++] = c;
    }
    stringa[i] = '\0';
    return stringa;
}
