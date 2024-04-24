#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROZ 100

char *deleteLastChar(char *s)
{
    int rozmiar = strlen(s);
    char *tab1 = malloc(rozmiar * sizeof(char));

    if (tab1 == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    strncpy(tab1, s, rozmiar - 1);
    tab1[rozmiar - 1] = '\0';

    free(s);

    return tab1;
}

int main()
{
    char tab1[ROZ];
    char *tab2;

    printf("Enter a string: ");
    fgets(tab1, ROZ, stdin);

    int l = strlen(tab1);

    tab2 = malloc((l + 1) * sizeof(char));
    if (tab2 == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    strcpy(tab2, tab1);

    for (int i = 0; i < l; i++)
    {
        printf("%s\n", tab2);
        tab2 = deleteLastChar(tab2);
    }

    free(tab2);

    return 0;
}
