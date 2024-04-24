#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROZ 100

char *deleteLastChar(char *s)
{
    int rozmiar, i;
    char *tab1;

    rozmiar = strlen(s);
    tab1 = (char *)malloc(rozmiar * sizeof(char)); // Allocate memory for the new string

    for (i = 0; i < rozmiar - 1; i++)
    {
        tab1[i] = s[i];
    }
    tab1[i] = '\0'; // Null-terminate the string

    free(s); // Free the old string

    return tab1;
}

int main()
{
    char tab1[ROZ], *tab2;
    int l, i;

    printf("podaj napis\n");
    fgets(tab1, 100, stdin);

    l = strlen(tab1);
    tab2 = malloc((l + 1) * sizeof(char)); // Allocate memory for tab2 and copy tab1
    strcpy(tab2, tab1);

    printf("%s\n", tab2); // Print the initial string

    while (strlen(tab2) > 0)
    {
        tab2 = deleteLastChar(tab2);
        printf("%s\n", tab2);
    }

    free(tab2); // Free the final string

    return 0;
}
