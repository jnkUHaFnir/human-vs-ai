#include <stdio.h>

#define BUFFER 100

int main() {
    char tab[BUFFER];
    FILE *wp = fopen("tab_file_b_words.txt", "r");
    if(wp == NULL) {
        printf("error\n");
        return -1;
    }
    
    int i = 0;
    while (fscanf(wp, "%s", &tab[i]) == 1 && i < BUFFER) {
        i++;
    }

    printf("Content: \n");
    for(int j = 0; j < i; j++) {
        printf("%s\n", &tab[j]);
    }

    fclose(wp);
    return 0;
}
