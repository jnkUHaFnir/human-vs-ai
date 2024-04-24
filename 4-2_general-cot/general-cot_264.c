#include <stdio.h>

#define BUFFER 100

int main() {
    char tab[BUFFER][BUFFER]; // Changed to a 2D array to store multiple words
    FILE *wp;
    wp = fopen("tab_file_b_words.txt", "r");
    if(wp == NULL) {
        printf("error/n");
        return -1;
    }
    int i;
    for(i = 0; i < BUFFER; i++) {
        if (fscanf(wp, "%s", tab[i]) != 1) // Check the return value of fscanf
            break;
    }
    printf("Content: \n");
    for(i = 0; i < BUFFER; i++) {
        if(tab[i][0] != '\0') // Check for end of string correctly
            printf("%s\n", tab[i]);
        else 
            break;
    }
    fclose(wp);
    return 0;
}
