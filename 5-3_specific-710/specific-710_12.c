#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *in = fopen("input.txt", "r");
    if(in == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[50];
    int count = 0;
    
    // Count the number of lines in the file
    while(fgets(line, sizeof(line), in) != NULL) {
        count++;
    }

    // Reset the file pointer to the beginning of the file
    rewind(in);

    // Dynamically allocate memory for array of strings
    char **lines = (char **)malloc(count * sizeof(char *));
    
    int i = 0;
    while(fgets(line, sizeof(line), in) != NULL) {
        lines[i] = strdup(line);
        i++;
    }

    // Do something with each line
    for(int j = 0; j < count; j++) {
        printf("Line %d: %s", j+1, lines[j]);
    }

    // Free allocated memory
    for(int k = 0; k < count; k++) {
        free(lines[k]);
    }
    free(lines);

    fclose(in);

    return 0;
}
