#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ROZ 100

char *deleteLastChar(char* s) {
    int rozmiar = strlen(s);
    if (rozmiar == 0) {
        free(s); // If string is already empty, free it and return NULL
        return NULL;
    }
    char *tab1 = (char*)malloc(rozmiar * sizeof(char)); // Allocate space for rozmiar characters, including room for '\0'
    memcpy(tab1, s, rozmiar-1); // Copy all but the last character
    tab1[rozmiar - 1] = '\0'; // Add a null terminator at the end

    free(s); // Free the old string
    return tab1;
}

int main()
{
    char tab1[ROZ], *tab2;
    int l, i;

    printf("podaj napis\n");
    fgets(tab1, ROZ, stdin);
    tab1[strcspn(tab1, "\n")] = 0; // Removing the newline character

    l=strlen(tab1) + 1; // Include space for '\0'
    tab2=malloc(l * sizeof(char));
    if (tab2==NULL) {
        printf("blad");
        return 1;
    }
    strcpy(tab2, tab1); // Copy the input string into tab2

    while(strlen(tab2) > 0) {
        tab2 = deleteLastChar(tab2);
        printf("%s\n", tab2);
    }

    free(tab2); // Final cleanup

    return 0;
}
