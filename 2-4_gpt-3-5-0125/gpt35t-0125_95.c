#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ROZ 100

char *deleteLastChar(char* s)
{
    int rozmiar,i;
    rozmiar = strlen(s);
    char *tab1 = (char*)malloc(rozmiar * sizeof(char));

    for(i = 0; i < rozmiar - 1; i++)
    {
        tab1[i] = s[i];
    }
    tab1[rozmiar - 1] = '\0';
    free(s);

    return tab1;
}

int main()
{
    char tab1[ROZ], *tab2;
    int l,i,p,a;

    printf("podaj napis\n");
    fgets(tab1, 100, stdin);

    l = strlen(tab1);
    tab1[l - 1] = '\0'; // Remove the newline character

    tab2 = strdup(tab1); // Duplicate tab1
    p = strlen(tab2);

    for(i = 0; i < p; i++)
    {
        printf("%s\n", tab2);
        tab2 = deleteLastChar(tab2);
        p = strlen(tab2);
    }

    free(tab2);

    return 0;
}
