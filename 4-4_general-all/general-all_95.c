#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROZ 100

char *deleteLastChar(char* s)
{
    int rozmiar, i;
    char *tab1;

    rozmiar = strlen(s);
    tab1 = (char*)malloc(rozmiar); // Allocate memory to store the shortened string
    if (tab1 == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (i = 0; i < rozmiar - 1; i++) {
        tab1[i] = s[i];
    }
    tab1[rozmiar - 1] = '\0'; // Add null terminator to the end of the string

    free(s); // Free the memory of the original string

    return tab1;
}

int main()
{
    char tab1[ROZ];
    char *tab2;
    int l, i, a;

    printf("Enter a string: ");
    fgets(tab1, sizeof(tab1), stdin);

    l = strlen(tab1);
    tab1[l - 1] = '\0'; // Remove the newline character from fgets input

    tab2 = malloc((l + 1) * sizeof(char)); // Allocate memory for the new string
    if (tab2 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    strcpy(tab2, tab1); // Copy the input string to tab2

    while (strlen(tab2) > 0) {
        tab2 = deleteLastChar(tab2);
        printf("%s\n", tab2);
    }

    free(tab2); // Free the memory of the final string

    return 0;
}
