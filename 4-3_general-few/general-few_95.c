#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROZ 100

char *deleteLastChar(char* s)
{
    int rozmiar, i;
    char *tab1;

    rozmiar = strlen(s);
    tab1 = (char*)malloc(rozmiar * sizeof(char));
    
    for(i = 0; i < (rozmiar - 1); i++)
    {
        tab1[i] = s[i];
    }
    tab1[rozmiar - 1] = '\0'; // Add null terminator to make it a valid string
    // Free the original string as we are done with it
    free(s);
    
    return tab1;
}

int main()
{
    char tab1[ROZ], *tab2;
    int l, i;

    printf("podaj napis\n");
    fgets(tab1, ROZ, stdin);

    l = strlen(tab1);
    tab2 = malloc((l + 1) * sizeof(char)); // Allocate memory for the string including null terminator
    
    if (tab2 == NULL)
    {
        printf("blad");
        return 1;
    }

    strcpy(tab2, tab1); // Copy the input string to tab2
    tab2[l - 1] = '\0'; // Delete the last character
    
    printf("%s\n", tab2);
    
    // Repeat the process until there are no more characters
    while (strlen(tab2) > 0)
    {
        tab2 = deleteLastChar(tab2);
        printf("%s\n", tab2);
    }
    
    // Free the dynamically allocated memory
    free(tab2);

    return 0;
}
