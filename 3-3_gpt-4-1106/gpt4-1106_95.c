#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *deleteLastChar(char *s)
{
    int rozmiar = strlen(s);
    if (rozmiar > 0)
    {
        s[rozmiar - 1] = '\0';  // Simply setting the last character to null terminator
    }
    return s;
}

int main()
{
    char tab1[100], *tab2;
    int l, i;

    printf("Enter a string:\n");

    if (fgets(tab1, sizeof(tab1), stdin) != NULL) 
    {
        l = strlen(tab1);
        if (tab1[l-1] == '\n') // Remove newline character if present
            tab1[l-1] = '\0';
            
        tab2 = malloc((l + 1) * sizeof(char)); // + 1 for the null terminator
        if (tab2 == NULL)
        {
            printf("Error allocating memory");
            return 1;
        }
        
        strcpy(tab2, tab1); // Copy the input string into dynamically allocated memory
        
        for(i = l; i > 0; i--)
        {
            deleteLastChar(tab2);
            printf("%s\n", tab2);
        }
        
        free(tab2); // Free the allocated memory when we are done
    }

    return 0;
}
