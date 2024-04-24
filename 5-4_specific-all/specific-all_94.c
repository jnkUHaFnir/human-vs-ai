#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROZ 100

char *deleteLastChar(char *s) {
    int rozmiar, i;
    char *tab1;

    rozmiar = strlen(s);
    tab1 = (char *)malloc(rozmiar * sizeof(char));
    if (tab1 == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (i = 0; i < (rozmiar - 1); i++) {
        tab1[i] = s[i];
    }
    tab1[rozmiar - 1] = '\0'; // Add null terminator to the new string

    free(s);

    return tab1;
}

int main() {
    char tab1[ROZ];
    char *tab2;
    int l, i, p, a;

    printf("Enter a string: ");
    fgets(tab1, ROZ, stdin);

    l = strlen(tab1);
    tab1[l - 1] = '\0'; // Remove newline character from input

    tab2 = malloc(l * sizeof(char));
    if (tab2 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    strcpy(tab2, tab1); // Copy input into tab2

    for (i = 0; i < l - 1; i++) {
        tab2 = deleteLastChar(tab2);
        p = strlen(tab2);

        for (a = 0; a < p; a++) {
            printf("%c", tab2[a]);
        }
        printf("\n");
    }

    free(tab2);

    return 0;
}
