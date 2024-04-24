#include <stdio.h>
#include <stdlib.h>

char *readline(FILE *fp) {
    char *buffer = NULL;
    char ch;
    int i = 0;
    size_t buff_len = 0;
    
    buffer = malloc(sizeof(char)); // Allocate initial memory for a character
    
    while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
        ++buff_len;
        char *temp = realloc(buffer, (buff_len + 1) * sizeof(char)); // Reallocate memory for each character
        
        if (temp == NULL) {
            free(buffer);
            return NULL; // Memory allocation failed
        } else {
            buffer = temp;
        }
        
        buffer[i] = ch;
        ++i;
    }
    
    // Add null terminator at the end of the string
    char *temp = realloc(buffer, (buff_len + 1) * sizeof(char));
    if (temp == NULL) {
        free(buffer);
        return NULL;
    }
    
    buffer = temp;
    buffer[i] = '\0';

    return buffer;
}

int main() {
    FILE *fp = fopen("example.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    char *line = readline(fp);
    if (line == NULL) {
        perror("Error reading line");
        fclose(fp);
        return 1;
    }

    printf("Read line: %s\n", line);

    free(line);
    fclose(fp);

    return 0;
}
