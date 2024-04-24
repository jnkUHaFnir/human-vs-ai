#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ROZ 100

char *deleteLastChar(char* s)
{
    int rozmiar, i;
    char *tab1;

    rozmiar = strlen(s);
    tab1 = malloc(rozmiar * sizeof(char)); // Allocate memory for tab1 same size as s

    for(i = 0; i < rozmiar - 1; i++)
    {
        tab1[i] = s[i];
    }
    tab1[rozmiar - 1] = '\0'; // Add null terminator at the end

    free(s); // Free memory allocated for input string

    return tab1;
}

int main()
{
    char tab1[ROZ];
    char *tab2;
    int l, i, p, a;

    printf("podaj napis\n");

    fgets(tab1, 100, stdin);

    l = strlen(tab1);
    tab1[l - 1] = '\0'; // Remove the newline character from input

    tab2 = strdup(tab1); // Allocate memory and copy tab1 to tab2

    for(i = 0; i < l - 1; i++)
    {
        p = strlen(tab2);
        printf("%s\n", tab2);

        char *temp = deleteLastChar(tab2);
        free(tab2); // Free memory allocated for previous tab2
        tab2 = temp;
    }

    free(tab2); // Free memory allocated for final tab2

    return 0;
}
