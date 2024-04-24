#include <stdio.h>
#include <stdlib.h>

#define BUFFER 100
#define MAX_WORD_LENGTH 30

int main() {
    char tab[BUFFER][MAX_WORD_LENGTH];  // each string should have its place
    FILE *wp;
    wp = fopen("tab_file_b_words.txt", "r");
    if(wp == NULL)
    {
        printf("error/n");
        return -1;
    }
    int i = 0;
    
    // keep reading words until end of file or MAX number is reached
    while(fscanf(wp, "%s", tab[i]) != EOF && i < BUFFER) {
        i++;
    }
    int totalWords = i;  // keep track of actual number of words read
    
    printf("Content: \n");
    // using totalWords here, prevents us from printing uninitialized array elements
    for(i = 0; i < totalWords; i++) {
        printf("%s\n", tab[i]);
    }
    fclose(wp);
    return 0;
}
