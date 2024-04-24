#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ROZ 100

char* deleteLastChar(char* s)
{
    int rozmiar, i;
    char* tab1;

    rozmiar = strlen(s);
    tab1 = (char*)malloc(rozmiar * sizeof(char)); // Corrected memory allocation
    if (tab1 == NULL)
    {
        printf("Memory allocation failed.");
        exit(1);
    }

    for (i = 0; i < rozmiar - 1; i++)
    {
        tab1[i] = s[i];
    }
    tab1[rozmiar - 1] = '\0'; // Null-terminate the new string
    free(s); // Free the original string after copying

    return tab1;
}

int main()
{
    char tab1[ROZ], *tab2;
    int l, i;

    printf("Enter a string: ");
    fgets(tab1, sizeof(tab1), stdin);
    l = strlen(tab1);

    tab2 = malloc((l - 1) * sizeof(char)); // Corrected memory allocation for tab2
    if (tab2 == NULL)
    {
        printf("Memory allocation failed.");
        exit(1);
    }

    strcpy(tab2, tab1); // Copy tab1 to tab2 to start processing on tab2

    for (i = 0; i < l; i++)
    {
        printf("%s\n", tab2);
        tab2 = deleteLastChar(tab2); // Delete the last character from tab2
    }

    free(tab2); // Free tab2 after all characters are deleted

    return 0;
}
