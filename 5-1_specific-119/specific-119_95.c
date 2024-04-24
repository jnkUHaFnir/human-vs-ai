#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ROZ 100

char *deleteLastChar(char *s) {
    int rozmiar, i;
    char *tab1;

    rozmiar = strlen(s);
    // Allocate memory for shortened string and null terminator
    tab1 = (char*)malloc(rozmiar * sizeof(char));
    
    for (i = 0; i < rozmiar - 1; i++) {
        tab1[i] = s[i];
    }
    tab1[rozmiar - 1] = '\0'; // Add null terminator
    free(s); // Free the original string

    return tab1;
}

int main() {
    char tab1[ROZ], *tab2;
    int l, i;

    printf("podaj napis\n");
    fgets(tab1, 100, stdin);
    
    l = strlen(tab1);
    tab1[l - 1] = '\0'; // Remove the newline character at the end

    tab2 = strdup(tab1); // Duplicate tab1 to tab2
    if (tab2 == NULL) {
        printf("Blad\n");
        return 1;
    }

    for (i = 0; i < l - 1; i++) {
        printf("%s\n", tab2);
        tab2 = deleteLastChar(tab2);
    }

    free(tab2); // Free the final string
    
    return 0;
}
