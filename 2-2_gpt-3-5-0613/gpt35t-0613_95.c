#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *deleteLastChar(char* s)
{
    int rozmiar = strlen(s);
    char *tab1 = malloc(rozmiar * sizeof(char));

    if (tab1 == NULL) {
        printf("Memory allocation failed");
        return NULL;
    }

    strncpy(tab1, s, rozmiar - 1); // Copy all characters except the last one
    tab1[rozmiar - 1] = '\0'; // Add null-terminating character

    free(s); // Free memory of the original string

    return tab1;
}

int main()
{
    char tab1[ROZ], *tab2;
    int l, i, p, a;

    printf("Enter a string: ");
    fgets(tab1, ROZ, stdin);

    l = strlen(tab1);
    tab1[l - 1] = '\0'; // Remove newline character

    tab2 = malloc((l + 1) * sizeof(char));
    if (tab2 == NULL) {
        printf("Memory allocation failed");
        return 0;
    }

    strcpy(tab2, tab1); // Copy tab1 to tab2

    for (i = 0; i < l; i++) {
        tab2 = deleteLastChar(tab2);
        p = strlen(tab2);

        for (a = 0; a < p; a++) {
            printf("%c", tab2[a]);
        }
        printf("\n");
    }

    free(tab2); // Free memory of the final string

    return 0;
}
