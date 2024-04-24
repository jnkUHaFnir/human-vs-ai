#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *deleteLastChar(char* s)
{
    if (s == NULL)
        return NULL;

    int rozmiar = strlen(s);
    if (rozmiar == 0)
        return NULL;

    char *tab1 = (char*)malloc(rozmiar * sizeof(char)); // Allocate memory for a new string, with the size one less than the original.
    if (tab1 == NULL)
        return NULL; // if malloc failed, return NULL

    strncpy(tab1, s, rozmiar - 1); // Copy all but the last character from the original string.
    tab1[rozmiar - 1] = '\0'; // Properly null-terminate the new string.

    return tab1; // Return the new string with the last character deleted.
}

int main() // Corrected the return type of main.
{
    char tab1[100], *tab2; // Define ROZ or replace with an actual number.
    int l, i;

    printf("podaj napis\n");

    if(fgets(tab1, sizeof(tab1), stdin) == NULL) return 1; // Check for fgets failure.

    l=strlen(tab1);
    if(tab1[l - 1] == '\n')
        tab1[l - 1] = '\0'; // Remove the newline character from the input.

    tab2=malloc((l + 1) * sizeof(char)); // Allocate memory for the copy, including the space for the null terminator.
    if (tab2 == NULL) {
        printf("blad");
        return 1;
    }
    strcpy(tab2, tab1); // Copy the entire input into tab2.

    for(i=0; i < l; i++) {
        char *newTab2 = deleteLastChar(tab2);
        if (newTab2 == NULL)
            break; // If the function returned NULL, there's nothing more to delete.

        free(tab2); // Free the old tab2 before we overwrite the pointer.
        tab2 = newTab2; // Update tab2 to point to the new string with the last character removed.

        printf("%s\n", tab2); // Print the current state of tab2.
    }

    free(tab2); // Free tab2 when we're done with it.
    return 0;
}
