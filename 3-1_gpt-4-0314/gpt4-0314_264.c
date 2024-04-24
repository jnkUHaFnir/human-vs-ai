#include <stdio.h>
#include <stdlib.h> // include this to use calloc and free functions

#define BUFFER 100
#define MAX_WORD_LENGTH 50 // added constant for maximum expected word length

int main() {
    char (*tab)[MAX_WORD_LENGTH] = (char(*)[MAX_WORD_LENGTH])calloc(BUFFER, sizeof(char[MAX_WORD_LENGTH])); // changed tab to a pointer to an array of fixed-size char arrays, and allocated memory using calloc
    FILE *wp;

    wp = fopen("tab_file_b_words.txt", "r");
    if (wp == NULL) {
        printf("error\n"); // fixed the escaped character
        free(tab); // added free before return
        return -1;
    }

    int i;
    for (i = 0; i < BUFFER; i++) {
        if (fscanf(wp, "%s", tab[i]) == EOF) { // modified to check for EOF instead of NULL
            break;
        }
    }

    printf("Content: \n");
    for (i = 0; i < BUFFER; i++) {
        if (tab[i][0] != '\0') { // check for the end of the array by checking if the first character is null '\0'
            printf("%s\n", tab[i]);
        } else {
            break;
        }
    }

    fclose(wp);
    free(tab); // added free to release memory
    return 0;
}
