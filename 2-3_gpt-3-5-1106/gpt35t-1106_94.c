#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ROZ 100

char *deleteLastChar(char* s)
{
    int rozmiar = strlen(s);
    char *tab1 = (char*)malloc(rozmiar * sizeof(char));
    strncpy(tab1, s, rozmiar - 1);
    tab1[rozmiar - 1] = '\0';  // Add null terminator at the end
    free(s);
    return tab1;
}

int main()
{
    char tab1[ROZ];
    printf("podaj napis: ");
    fgets(tab1, ROZ, stdin);
    int l = strlen(tab1);
    
    char *tab2 = malloc((l + 1) * sizeof(char));  // Allocate memory for original string + null terminator
    strcpy(tab2, tab1);  // Copy original string into tab2
    
    for(int i = 0; i < l; i++)
    {
        printf("%s\n", tab2);  // Print the current string
        tab2 = deleteLastChar(tab2);  // Delete the last character
    }
    
    free(tab2);
    return 0;
}
