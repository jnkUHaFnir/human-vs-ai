#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ROZ 100

char *deleteLastChar(char* s) {
    int rozmiar;
    char *tab1;

    rozmiar = strlen(s);
    // Allocate memory for rozmiar characters (rozmiar-1 characters + '\0')
    tab1 = (char*)malloc(rozmiar * sizeof(char));
    if (!tab1) return NULL; // Memory allocation check

    for (int i = 0; i < rozmiar-1; i++) {
        tab1[i] = s[i];
    }
    tab1[rozmiar-1] = '\0'; // Null-terminate the string
    free(s); // Free the original string
    return tab1;
}

int main() {
    char tab1[ROZ], *tab2;
    int l, i;

    printf("podaj napis\n");
    fgets(tab1, 100, stdin);
    tab1[strcspn(tab1, "\n")] = 0; // Remove the newline character

    l = strlen(tab1);
    tab2 = (char*) malloc((l+1) * sizeof(char)); // Allocate memory properly
    strcpy(tab2, tab1); // Copy the initial string to dynamically allocated memory

    for(i = l; i > 0; i--) {
        tab2 = deleteLastChar(tab2); // Update tab2 with the shortened string
        if (!tab2) break; // Check for memory allocation failure
        printf("%s\n", tab2); // Use %s to print the string directly
    }

    free(tab2); // Free the final allocated memory
    return 0;
}
