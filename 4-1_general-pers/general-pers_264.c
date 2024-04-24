#include <stdio.h>
#include <string.h> // Include string.h for string functions

#define BUFFER 100

int main() {
    char tab[BUFFER][BUFFER];  // Define a 2D array to store strings
    FILE *wp;
    wp = fopen("tab_file_b_words.txt", "r");
    if(wp == NULL)
    {
        printf("error\n"); // Corrected error message format specifier
        return -1;
    }
    
    int i;
    for(i=0; i<BUFFER; i++) { // Changed sizeof(wp) to BUFFER to loop over BUFFER elements
        if(fscanf(wp, "%s", tab[i]) != 1) { // Read string directly to tab[i]
            break;
        }
    }
    
    printf("Content: \n");
    for(i = 0; i < BUFFER; i++) {
        if(strlen(tab[i]) > 0) { // Check if the string is not empty
            printf("%s\n", tab[i]);
        } else {
            break;
        }
    }
    
    fclose(wp);
    return 0;
}
