#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 100

char* read_popen_output(FILE* stream) {
    char* buffer = (char*)malloc(INITIAL_SIZE * sizeof(char));
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }

    size_t total_size = INITIAL_SIZE;
    size_t current_size = 0;
    char* line = NULL;

    while (fgets(line, total_size - current_size, stream)) {
        size_t len = strlen(line);
        if (current_size + len >= total_size) {
            total_size *= 2;
            buffer = (char*)realloc(buffer, total_size);
            if (!buffer) {
                fprintf(stderr, "Memory reallocation failed.\n");
                free(line);
                return NULL;
            }
        }
        strcat(buffer, line);
        current_size += len;
    }

    free(line);
    return buffer;
}

int main() {
    FILE *tmp1;
    char *artist;

    tmp1 = popen("cmus-remote -Q | grep 'tag artist' | sed s/'tag artist'/''/g | sed '1s/^.//'", "r");
    
    if (tmp1 == NULL) {
        perror("Failed to run command");
        return 1;
    }

    artist = read_popen_output(tmp1);

    if (artist) {
        printf("Artist: %s\n", artist);
        free(artist);
    } else {
        fprintf(stderr, "Failed to read popen output.\n");
    }

    pclose(tmp1);

    return 0;
}
