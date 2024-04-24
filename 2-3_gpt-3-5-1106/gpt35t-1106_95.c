#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ROZ 100

char *deleteLastChar(char* s)
{
    int rozmiar = strlen(s);
    char *tab1 = (char*)malloc(rozmiar * sizeof(char)); // Allocate memory for new string

    if (tab1 == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }

    // Copy all characters except the last one
    for(int i = 0; i < rozmiar - 1; i++)
    {
        tab1[i] = s[i];
    }
    tab1[rozmiar - 1] = '\0'; // Add null terminator to the end

    free(s); // Free the memory of the original string

    return tab1;
}

int main()
{
    char tab1[ROZ], *tab2;
    int l;

    printf("podaj napis\n");
    fgets(tab1, 100, stdin);

    l = strlen(tab1);
    if (tab1[l-1] == '\n') {
        tab1[l-1] = '\0'; // Remove the newline character from the input
    }

    tab2 = strdup(tab1); // Allocate memory and copy tab1 to tab2

    while(strlen(tab2) > 0) {
        printf("%s\n", tab2);
        tab2 = deleteLastChar(tab2);
    }

    free(tab2); // Free the memory of tab2

    return 0;
}
