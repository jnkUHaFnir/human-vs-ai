#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROZ 100

char *deleteLastChar(char *s) {
    int rozmiar, i;
    char *tab1;

    rozmiar = strlen(s);
    tab1 = (char *)malloc(rozmiar * sizeof(char)); // Allocate memory based on current size

    for (i = 0; i < rozmiar - 1; i++) {
        tab1[i] = s[i];
    }
    tab1[rozmiar - 1] = '\0'; // Add null terminator at the end of the new string

    free(s); // Free the memory of original string

    return tab1;
}

int main() {
    char tab1[ROZ], *tab2;
    int l, i, p, a;

    printf("Input a string: ");
    fgets(tab1, ROZ, stdin);

    tab1[strcspn(tab1, "\n")] = 0; // Remove newline character from fgets input

    l = strlen(tab1);
    tab2 = malloc((l + 1) * sizeof(char)); // Allocate memory for tab2 with additional space for null terminator

    if (tab2 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    strcpy(tab2, tab1); // Copy the initial string to tab2

    for (i = 0; i < l; i++) {
        p = strlen(tab2);
        for (a = 0; a < p; a++) {
            printf("%c", tab2[a]);
        }
        printf("\n");

        tab2 = deleteLastChar(tab2);
    }

    free(tab2); // Free the memory of the final string

    return 0;
}
