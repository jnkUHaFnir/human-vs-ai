#include <stdio.h>

#define BUFFER 100
#define WORD_SIZE 20

int main() {
    char tab[BUFFER][WORD_SIZE]; // 2D array to store words
    FILE *wp;
    wp = fopen("tab_file_b_words.txt", "r");
    if(wp == NULL) {
        printf("Error opening file\n");
        return -1;
    }
    
    int i;
    for(i = 0; i < BUFFER; i++) {
        if (fscanf(wp, "%19s", tab[i]) != 1) // Read up to WORD_SIZE-1 characters to avoid buffer overflow
            break;
    }
    
    printf("Content: \n");
    for(i = 0; i < BUFFER; i++) {
        if(tab[i][0] != '\0') // Check if the first character is not null terminator
            printf("%s\n", tab[i]);
        else
            break;
    }
    
    fclose(wp);
    return 0;
}
