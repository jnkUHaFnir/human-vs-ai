#include <stdio.h>
#include <stdlib.h>

#define BUFFER 100
#define MAX_WORDS 1000

int main() {
    char tab[MAX_WORDS][BUFFER]; // 2D array for storing words
    FILE *wp;
    wp = fopen("tab_file_b_words.txt", "r");
    if(wp == NULL) {
        printf("Error opening file\n");
        return -1;
    }
    
    int i = 0;
    while(fscanf(wp, "%99s", tab[i]) == 1 && i < MAX_WORDS - 1) {
        i++;
    }
    int totalWords = i; // Total number of words read

    printf("Content: \n");
    for(i = 0; i < totalWords; i++) {
        printf("%s\n", tab[i]);
    }

    fclose(wp);
    return 0;
}
