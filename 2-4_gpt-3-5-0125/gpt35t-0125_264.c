#include <stdio.h>

#define BUFFER 100

int main() {
    char tab[BUFFER][BUFFER];
    FILE *wp;
    wp = fopen("tab_file_b_words.txt", "r");
    if(wp == NULL)
    {
        printf("error/n");
        return -1;
    }
    int i = 0;
    while(fscanf(wp, "%s", tab[i]) != EOF && i < BUFFER) {
        i++;
    }
    printf("Content: \n");
    for(i = 0; i < BUFFER; i++) {
        if(tab[i][0] != '\0')
            printf("%s\n", tab[i]);
        else 
            break;
    }
    fclose(wp);
    return 0;
}
