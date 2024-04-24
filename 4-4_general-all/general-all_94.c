#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROZ 100

char *deleteLastChar(char *s) {
    int rozmiar, i;
    char *tab1;

    rozmiar = strlen(s);
    tab1 = malloc(rozmiar); // Allocate memory for the modified string
    
    if(tab1 == NULL) {
        printf("Blad alokacji pamieci\n");
        exit(1);
    }

    for (i = 0; i < rozmiar - 1; i++) {
        tab1[i] = s[i];
    }

    tab1[rozmiar - 1] = '\0'; // Add null terminator at the end
    free(s); // Free the original string
    return tab1;
}

int main() {
    char tab1[ROZ], *tab2;
    int l, i, p;

    printf("Podaj napis: ");
    fgets(tab1, ROZ, stdin);

    l = strlen(tab1);
    tab2 = malloc((l + 1) * sizeof(char)); // Allocate memory for null-terminated string

    if (tab2 == NULL) {
        printf("Blad alokacji pamieci\n");
        return 1;
    }

    strcpy(tab2, tab1); // Copy input string to tab2

    while (strlen(tab2) > 0) {
        printf("%s\n", tab2);
        tab2 = deleteLastChar(tab2);
    }

    free(tab2); // Free the final modified string
    return 0;
}
