#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ROZ 100

char *deleteLastChar(char* s)
{
    int rozmiar, i;
    char *tab1;

    rozmiar = strlen(s);
    tab1 = (char*)malloc((rozmiar-1) * sizeof(char)); // Corrected sizeof(char)
    
    for(i = 0; i < (rozmiar - 1); i++)
    {
        tab1[i] = s[i];
    }
    
    free(s); // Free the memory allocated for the input string after creating the new one
    return tab1;
}

int main()
{
    char tab1[ROZ], *tab2;
    int l, i, p, a;

    printf("podaj napis\n");
    fgets(tab1, 100, stdin);
    
    l = strlen(tab1);     
    tab2 = malloc(l * sizeof(char)); // Corrected sizeof(char)
    if (tab2 == NULL)
    {
        printf("blad");
        return 1;
    }

    strcpy(tab2, tab1); // Copy original input string to tab2

    for(i = 0; i < l; i++)
    {
        tab2 = deleteLastChar(tab2); // Call deleteLastChar on original input string
        p = strlen(tab2);
        
        for(a = 0; a < p; a++)
        {
            printf("%c", tab2[a]);
        }
        printf("\n"); // Print a newline after each iteration
    }

    free(tab2); // Free the memory allocated for the final string

    return 0;
}
