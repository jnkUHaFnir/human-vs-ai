#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ROZ 100

char *deleteLastChar(char* s) {
    int rozmiar, i;
    char *tab1;

    rozmiar = strlen(s);
    tab1 = (char*)malloc(rozmiar * sizeof(char)); // Allocate enough memory to hold the new string
    
    for(i = 0; i < rozmiar - 1; i++) {
        tab1[i] = s[i];
    }
    tab1[i] = '\0'; // Add null-terminator at the end of the new string
    free(s); // Free the memory allocated for the original string

    return tab1;
}

int main() {
    char tab1[ROZ], *tab2;
    int l, i, p, a;

    printf("Enter a string: ");
    fgets(tab1, ROZ, stdin);

    l = strlen(tab1);
    tab2 = malloc((l + 1) * sizeof(char)); // Allocate memory for the original string
    
    if (tab2 == NULL) {
        printf("Memory allocation failed");
        return 1;
    }

    strcpy(tab2, tab1); // Copy the string to tab2

    for(i = 0; i < l; i++) {
        tab2 = deleteLastChar(tab2);
        p = strlen(tab2);
        for(a = 0; a < p; a++) {
            printf("%c", tab2[a]);
        }
        printf("\n");
    }

    free(tab2); // Free the memory allocated for the final string

    return 0;
}
