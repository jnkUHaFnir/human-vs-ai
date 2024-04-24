#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ROZ 100

char* deleteLastChar(char* s) {
    int rozmiar, i;
    char* tab1;

    rozmiar = strlen(s);
    tab1 = (char*)malloc(rozmiar * sizeof(char)); // Allocate memory for the same size as s
    if (tab1 == NULL) {
        printf("Memory allocation failed");
        return NULL;
    }

    for (i = 0; i < rozmiar - 1; i++) {
        tab1[i] = s[i];
    }
    tab1[rozmiar - 1] = '\0'; // Add null terminator to the end of the new string

    free(s); // Free the memory allocated for the original string
    return tab1;
}

int main() {
    char tab1[ROZ];
    char* tab2;
    int l, i, p;

    printf("Enter a string: ");
    fgets(tab1, ROZ, stdin);

    l = strlen(tab1);
    tab1[l - 1] = '\0'; // Remove the newline character from fgets input

    tab2 = malloc((l+1) * sizeof(char)); // Allocate memory for tab2 (l + 1 for null terminator)
    if (tab2 == NULL) {
        printf("Memory allocation failed");
        return 1;
    }

    strcpy(tab2, tab1); // Copy tab1 to tab2

    while (strlen(tab2) > 0) {
        printf("%s\n", tab2);
        tab2 = deleteLastChar(tab2);
    }

    free(tab2); // Free the memory allocated for tab2

    return 0;
}
