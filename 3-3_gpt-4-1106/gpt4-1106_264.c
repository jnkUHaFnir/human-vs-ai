#include <stdio.h>

#define BUFFER 100
#define WORD_SIZE 20

int main() {
    char tab[BUFFER][WORD_SIZE];
    FILE *wp = fopen("tab_file_b_words.txt", "r");
    if(wp == NULL) {
        printf("error\n");
        return -1;
    }

    int i = 0;
    // Read words until the file ends or we reach the buffer limits.
    while (i < BUFFER && fscanf(wp, "%19s", tab[i]) == 1) {
        i++;
    }
    int totalWords = i;  // Store the total number of words read.

    printf("Content: \n");
    for(i = 0; i < totalWords; i++) {
        printf("%s\n", tab[i]);
    }

    fclose(wp);
    return 0;
}
