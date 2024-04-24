#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int i = 0, j;
    char string[100][100]; // Define a 2D array to store each line separately
    char line[100];
    FILE *file; 

    file = fopen("patt", "r"); 
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof line, file) != NULL) {
        if (i < 100) {
            printf("%d %s", i, line);
            strcpy(string[i], line); // Copy the content of line to string[i]
            i++;
        } else {
            printf("Exceeded the maximum number of lines.\n");
            break;
        }
    }

    for (j = 0; j < i; j++) {
        printf("string[%d] %s", j, string[j]);
    }

    fclose(file);
    return 0;
}
