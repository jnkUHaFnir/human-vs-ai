#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_BUFFER_SIZE 64

char* readFromPipe(FILE *pipe) {
    char *buffer = (char*)malloc(sizeof(char) * INITIAL_BUFFER_SIZE);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    size_t bufferSize = INITIAL_BUFFER_SIZE;
    size_t len = 0;
    char *line = NULL;

    while (fgets(line, sizeof(line), pipe) != NULL) {
        size_t lineLen = strlen(line);
        if (len + lineLen >= bufferSize) {
            bufferSize *= 2;
            char *tmp = realloc(buffer, bufferSize);
            if (tmp == NULL) {
                fprintf(stderr, "Memory reallocation failed\n");
                free(buffer);
                return NULL;
            }
            buffer = tmp;
        }
        strcpy(buffer + len, line);
        len += lineLen;
    }

    return buffer;
}

int main() {
    FILE *tmp1;
    char *artist;

    tmp1 = popen("cmus-remote -Q | grep 'tag artist' | sed s/'tag artist'/''/g | sed '1s/^.//'", "r");
    if (tmp1 == NULL) {
        fprintf(stderr, "Failed to open pipe\n");
        return 1;
    }

    artist = readFromPipe(tmp1);
    if (artist != NULL) {
        printf("Artist: %s\n", artist);
        free(artist); // Don't forget to free the allocated buffer when done
    }

    pclose(tmp1);

    return 0;
}
