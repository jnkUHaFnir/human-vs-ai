#include <stdio.h>
#include <stdlib.h>

int main() {
    int myArray[240][30];
    char line[240];
    char *token;
    int i, n, j;
    FILE *fp;
    
    fp = fopen("array_list.txt", "rt");
    
    if (fp == NULL){
        printf("Error opening file.\n");
        return 1;
    }
    
    j = 0;
    i = 0;
    
    while (fgets(line, sizeof(line), fp)) {
        token = strtok(line, " ");
        j = 0; // Reset column counter for new row
        
        while (token != NULL) {
            n = atoi(token);
            myArray[i][j] = n;
            j++; // Move to the next column
            token = strtok(NULL, " ");
        }
        
        // Print the elements stored in the row
        for (int k = 0; k < j; k++) {
            printf("%d ", myArray[i][k]);
        }
        printf("\n");
        
        i++; // Move to the next row
    }
    
    fclose(fp); // Close the file
    
    return 0;
}
