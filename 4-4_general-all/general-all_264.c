#include <stdio.h>

#define BUFFER 100
#define FILENAME "tab_file_b_words.txt"

int main() {
    char tab[BUFFER];
    FILE *wp;
    int i;

    wp = fopen(FILENAME, "r");
    if (wp == NULL) {
        printf("Error opening file %s\n", FILENAME);
        return -1;
    }

    // Read words from the file into the array
    for (i = 0; i < BUFFER && fscanf(wp, "%c", &tab[i]) != EOF; i++);

    printf("Content: \n");
    
    // Display the array data
    for (i = 0; i < BUFFER; i++) {
        if (tab[i] != '\0') {
            printf("%c\n", tab[i]);
        } else {
            break;
        }
    }
    
    fclose(wp);
    return 0;
}
