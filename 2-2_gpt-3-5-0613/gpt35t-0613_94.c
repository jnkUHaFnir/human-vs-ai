char *deleteLastChar(char* s)
{
    int rozmiar = strlen(s);
    char *tab1 = malloc(rozmiar * sizeof(char));

    if (rozmiar <= 1) {
        free(s);
        return NULL;
    }

    for (int i = 0; i < rozmiar - 1; i++) {
        tab1[i] = s[i];
    }
    
    free(s);
    return tab1;
}
int main()
{
    char tab1[ROZ], *tab2;
    int l;

    printf("podaj napis\n");
    fgets(tab1, ROZ, stdin);

    l = strlen(tab1);
    tab1[l - 1] = '\0'; // remove the newline character from fgets input

    tab2 = malloc((l + 1) * sizeof(char));
    if (tab2 == NULL) {
        printf("blad");
        return 1;
    }
    strcpy(tab2, tab1);

    while (tab2 != NULL) {
        printf("%s\n", tab2);
        tab2 = deleteLastChar(tab2);
    }

    return 0;
}
