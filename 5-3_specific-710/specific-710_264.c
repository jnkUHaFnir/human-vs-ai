#include <stdio.h>
#include <stdlib.h> // Include this for malloc

#define BUFFER 100

int main() {
    char **tab; // Change tab to pointer to char pointer
    FILE *wp;
    char word[BUFFER];
    int i = 0;

    wp = fopen("tab_file_b_words.txt", "r");
    if(wp == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    // Allocate memory for array of strings
    tab = (char**)malloc(BUFFER * sizeof(char*));
    if(tab == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }

    // Read words from file and store in array
    while (fscanf(wp, "%s", word) == 1 && i < BUFFER) {
        tab[i] = (char*)malloc(BUFFER * sizeof(char)); // Allocate memory for each word
        if(tab[i] == NULL) {
            printf("Memory allocation failed\n");
            return -1;
        }
        strcpy(tab[i], word);
        i++;
    }

    printf("Content: \n");
    for(int j = 0; j < i; j++) {
        printf("%s\n", tab[j]);
        free(tab[j]); // Free allocated memory for each word
    }

    free(tab); // Free allocated memory for array of strings
    fclose(wp);
    return 0;
}
