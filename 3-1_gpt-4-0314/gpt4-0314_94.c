#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROZ 100
char *deleteLastChar(char *s)
{
    int rozmiar, i;
    char *tab1;

    rozmiar = strlen(s);
    tab1 = (char *)malloc((rozmiar) * sizeof(char));
    for (i = 0; i < (rozmiar - 1); i++)
    {
        tab1[i] = s[i];
    }
    tab1[rozmiar - 1] = '\0';
    return tab1;
}

int main()
{
    char tab1[ROZ], *tab2;
    int l, i, p, a;

    printf("podaj napis\n");

    fgets(tab1, 100, stdin);

    l = strlen(tab1);
    tab2 = malloc(l * sizeof(char));
    if (tab2 == NULL)
    {
        printf("blad");
        return 1;
    }

    strcpy(tab2, tab1);
    for (i = 0; i < l; i++)
    {
        char *temp = deleteLastChar(tab2);
        printf("%s\n", temp);
        free(tab2);
        tab2 = temp;
    }

    free(tab2);
    return 0;
}
