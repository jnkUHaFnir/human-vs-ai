#include <stdio.h>
#include <stdlib.h>

int main() {
    int myArray[240][30];
    char line[240];
    char *token;
    int i, n, j;
    FILE *fp;
    
    fp = fopen("array_list.txt", "rt");
    
    j = 0;
    i = 0;
    
    while (fgets(line, sizeof(line), fp)) {
        token = strtok(line, " ");
        j = 0; // Reset column index for each new line
        
        while (token != NULL) {
            n = atoi(token);
            myArray[i][j] = n;
            printf("%d ", myArray[i][j]);
            j++;
            token = strtok(NULL, " "); // Move to the next token in the same line
        }

        printf("\n");
        i++;
    }
    
    fclose(fp); // Don't forget to close the file
    return 0;
}
