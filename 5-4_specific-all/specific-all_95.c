#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROZ 100

char *deleteLastChar(char *s)
{
    int rozmiar, i;
    char *tab1;

    rozmiar = strlen(s);
    // Allocate memory for new string with 1 less character
    tab1 = (char *)malloc(rozmiar * sizeof(char));
    
    // Copy characters from s to tab1 excluding the last character
    for (i = 0; i < rozmiar - 1; i++)
    {
        tab1[i] = s[i];
    }
    tab1[i] = '\0'; // Null-terminate the string
    
    // Free the input string s
    free(s);
    
    return tab1;
}

int main()
{
    char tab1[ROZ], *tab2;
    int l, i, p;

    printf("Podaj napis: ");
    fgets(tab1, ROZ, stdin);

    l = strlen(tab1);
    tab1[l - 1] = '\0'; // Removing the newline character from fgets input

    tab2 = strdup(tab1); // Duplicate input string to tab2
    if (tab2 == NULL)
    {
        printf("Blad alokacji pamieci");
        return 1;
    }

    while ((p = strlen(tab2)) > 0)
    {
        printf("%s\n", tab2);
        tab2 = deleteLastChar(tab2);
    }

    free(tab2); // Free the final string after the loop

    return 0;
}
