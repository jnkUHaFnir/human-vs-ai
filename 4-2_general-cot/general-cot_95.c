#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROZ 100

char *deleteLastChar(char* s) {
    int rozmiar = strlen(s);
    char *tab1 = (char*)malloc(rozmiar * sizeof(char)); // Allocate space for null terminator

    if (rozmiar <= 1) {
        free(s); // Free the input string memory
        return NULL; // Return NULL if there is no character to delete
    }

    // Copy all characters except the last one
    for (int i = 0; i < rozmiar - 1; i++) {
        tab1[i] = s[i];
    }
    tab1[rozmiar - 1] = '\0'; // Add null terminator

    free(s); // Free the input string memory
    return tab1;
}

int main() {
    char tab1[ROZ];
    printf("Podaj napis\n");
    fgets(tab1, ROZ, stdin);

    char *tab2 = strdup(tab1); // Initial string copy

    while (tab2 != NULL) {
        printf("%s\n", tab2);
        tab2 = deleteLastChar(tab2);
    }

    return 0;
}
