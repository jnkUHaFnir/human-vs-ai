#include <stdio.h>

#define BUFFER 100
#define MAX_WORD_SIZE 50

int main() {
    char tab[BUFFER][MAX_WORD_SIZE];
    FILE *wp;
    wp = fopen("tab_file_b_words.txt", "r");
    if (wp == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    int i;
    for (i = 0; i < BUFFER; i++) {
        if (fscanf(wp, "%49s", tab[i]) == 1) { // Read up to 49 characters to prevent buffer overflow
            // do something if needed
        }
        else {
            break;
        }
    }

    printf("Content:\n");
    for (i = 0; i < BUFFER; i++) {
        if (tab[i][0] != 0) {
            printf("%s\n", tab[i]);
        }
        else {
            break;
        }
    }

    fclose(wp);
    return 0;
}
