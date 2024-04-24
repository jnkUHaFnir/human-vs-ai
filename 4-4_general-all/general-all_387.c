#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 1024   // Size of each chunk to read

char *readFromFile(FILE *file) {
    char *buffer = NULL;
    char *tmp;
    size_t bufferSize = CHUNK_SIZE;
    size_t bytesRead = 0;

    buffer = (char *)malloc(bufferSize * sizeof(char));
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }

    while (1) {
        if (bytesRead + CHUNK_SIZE > bufferSize) {
            bufferSize *= 2;
            tmp = realloc(buffer, bufferSize * sizeof(char));
            if (tmp == NULL) {
                fprintf(stderr, "Memory reallocation failed.\n");
                free(buffer);
                return NULL;
            }
            buffer = tmp;
        }

        if (fgets(buffer + bytesRead, CHUNK_SIZE, file) == NULL) {
            break;  // End of file
        }

        bytesRead += strlen(buffer + bytesRead);

        if (bytesRead < bufferSize - 1 || buffer[bytesRead - 1] == '\n') {
            break;  // Read complete or end of line
        }
    }

    return buffer;
}

int main() {
    FILE *tmp1;
    char *artist;

    tmp1 = popen("cmus-remote -Q | grep 'tag artist' | sed s/'tag artist'/''/g | sed '1s/^.//'", "r");
    if (tmp1 == NULL) {
        fprintf(stderr, "Failed to execute command.\n");
        return 1;
    }

    artist = readFromFile(tmp1);

    // Check if memory allocation was successful and print the result
    if (artist != NULL) {
        printf("Artist: %s\n", artist);
        free(artist);  // Don't forget to free the memory when done
    }

    pclose(tmp1); // Close the FILE pointer before exiting

    return 0;
}
