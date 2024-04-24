#include <stdio.h>
#include <stdlib.h>

char *readline(FILE *fp) {
    char *buffer = NULL;
    char ch;
    int buff_len = 0;
    size_t buffer_size = 0;

    do {
        ch = fgetc(fp);

        if (ch == EOF) {
            break;
        }

        if (buff_len >= buffer_size - 1) {
            buffer_size += 10;
            char *tmp = realloc(buffer, buffer_size);
            if (tmp == NULL) {
                free(buffer);
                return NULL; // Error handling for realloc failure
            }
            buffer = tmp;
        }

        buffer[buff_len] = ch;
        buff_len++;
    } while (ch != '\n');

    // Resize the buffer to fit the actual length of the string
    char *resized_buffer = realloc(buffer, buff_len + 1);
    if (resized_buffer == NULL) {
        free(buffer);
        return NULL; // Error handling for realloc failure
    }

    buffer = resized_buffer;
    buffer[buff_len] = '\0'; // Null-terminate the string

    return buffer;
}

int main() {
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char *line = readline(file);
    printf("Read line: %s\n", line);

    free(line);
    fclose(file);
    return 0;
}
