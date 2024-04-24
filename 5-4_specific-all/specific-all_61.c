char * getString(void) {
    char *stringa = NULL, c;
    int i=0;
    stringa = malloc(sizeof(char) * 2); // Allocate space for the null terminator

    if (stringa == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    while((c = getchar()) != '\n'){
        stringa[i++] = c;
        stringa = (char *) realloc(stringa, (i+2) * sizeof(char)); // Reallocate space for the null terminator
        if (stringa == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
    }
    stringa[i] = '\0';
    return stringa;
}

...

// Modify string copying to avoid pointer assignments
strcpy(rub[idx].name, tmp);
strcpy(rub[idx].surname, tmp);
strcpy(rub[idx].address, tmp);
strcpy(rub[idx].number, tmp);
