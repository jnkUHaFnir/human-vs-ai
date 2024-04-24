#include <stdio.h>
#include <string.h>

#define BUFFER 100
#define WORD_LENGTH 20 // Maximum length of a word

int main() {
    char tab[BUFFER][WORD_LENGTH]; // 2D array to store words
    FILE *wp;
    wp = fopen("tab_file_b_words.txt", "r");
    if(wp == NULL)
    {
        printf("error\n");
        return -1;
    }
    int i = 0;
    while(fgets(tab[i], WORD_LENGTH, wp) != NULL) {
        tab[i][strcspn(tab[i], "\n")] = '\0'; // Remove newline character
        i++;
    }
    printf("Content: \n");
    for(int j = 0; j < i; j++) {
        printf("%s\n", tab[j]);
    }
    fclose(wp);
    return 0;
}
