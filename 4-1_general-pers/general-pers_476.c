#include <stdio.h>
#include <stdlib.h>

char *readline(FILE *fp) {
    char ch;
    int i = 0, buff_len = 1;
    char *buffer = malloc(buff_len);
    
    if(buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
        buffer[i] = ch;
        ++i;

        if (i >= buff_len) {
            buff_len *= 2;
            char *temp = realloc(buffer, buff_len);
            
            if (temp == NULL) {
                fprintf(stderr, "Memory reallocation failed\n");
                free(buffer);
                return NULL;
            }
            
            buffer = temp;
        }
    }
    
    buffer[i] = '\0'; // Null-terminate the string

    return buffer;
}

int main() {
    FILE *file = fopen("test.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    char *line = readline(file);
    if (line != NULL) {
        printf("Read line: %s\n", line);
        free(line); // Free dynamically allocated memory
    }

    fclose(file);

    return 0;
}
