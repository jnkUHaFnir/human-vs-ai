#include <stdio.h>
#include <stdlib.h>

char *readline(FILE *fp) {
    char ch;
    int buff_len = 1; // Start with 1 to include space for null terminator
    char *buffer = malloc(buff_len);

    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }

    int i = 0;
    while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
        if (i == buff_len - 1) { // Check if we need more space
            buff_len *= 2; // Double the buffer length
            char *temp = realloc(buffer, buff_len);
            if (temp == NULL) {
                fprintf(stderr, "Memory allocation failed.\n");
                free(buffer);
                return NULL;
            }
            buffer = temp;
        }

        buffer[i] = ch;
        i++;
    }
    
    buffer[i] = '\0'; // Add null terminator at the end

    return buffer;
}
