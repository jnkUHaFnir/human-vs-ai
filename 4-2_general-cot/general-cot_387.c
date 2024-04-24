#include <stdio.h>
#include <stdlib.h>

#define CHUNK_SIZE 1024

char* readOutput(FILE *stream) {
    char *buffer = NULL;
    size_t buffer_size = 0;
    size_t buffer_index = 0;
    int c;

    while ((c = fgetc(stream)) != EOF) {
        if (buffer_index == buffer_size) {
            buffer_size += CHUNK_SIZE;
            buffer = realloc(buffer, buffer_size);
            if (buffer == NULL) {
                perror("Memory allocation failed");
                exit(EXIT_FAILURE);
            }
        }
        buffer[buffer_index++] = c;
    }

    // Add null terminator at the end
    buffer = realloc(buffer, buffer_index + 1);
    buffer[buffer_index] = '\0';

    return buffer;
}

int main() {
    FILE *tmp1;
    char *artist;

    tmp1 = popen("cmus-remote -Q | grep 'tag artist' | sed s/'tag artist'/''/g | sed '1s/^.//'", "r");
    if (tmp1 == NULL) {
        perror("popen failed");
        return 1;
    }

    artist = readOutput(tmp1);

    // Use artist as needed

    // Don't forget to free the allocated memory when done
    if (artist != NULL) {
        free(artist);
    }

    pclose(tmp1);
    return 0;
}
