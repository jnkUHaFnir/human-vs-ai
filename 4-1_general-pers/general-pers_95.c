#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROZ 100

char *deleteLastChar(char *s) {
    int rozmiar, i;
    char *tab1;

    rozmiar = strlen(s);
    
    if (rozmiar <= 1) { // If the string is empty or has only one character, return an empty string
        free(s); // Free the original memory
        return strdup(""); // Return a new dynamically allocated empty string
    }
    
    tab1 = (char *)malloc(rozmiar * sizeof(char)); // Allocate memory for the new string
    
    for (i = 0; i < rozmiar - 1; i++) {
        tab1[i] = s[i];
    }
    
    tab1[rozmiar - 1] = '\0'; // Add null terminator to the new string
    free(s); // Free the original memory
    return tab1;
}

int main() {
    char tab1[ROZ], *tab2;
    int l, i;

    printf("Podaj napis:\n");
    fgets(tab1, sizeof(tab1), stdin);

    l = strlen(tab1);
    
    tab1[strcspn(tab1, "\n")] = '\0'; // Removing the newline character from fgets
    
    tab2 = strdup(tab1); // Copy the original string to a dynamically allocated memory
    
    if (tab2 == NULL) {
        printf("Blad alokacji pamieci.\n");
        return 1; // Return an error code
    }
    
    while (strlen(tab2) > 0) {
        printf("%s\n", tab2);
        tab2 = deleteLastChar(tab2);
    }

    free(tab2); // Free the final memory
    
    return 0;
}
