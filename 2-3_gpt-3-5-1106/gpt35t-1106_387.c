#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *tmp1;
    char *artist = NULL;
    size_t buffer_size = 128; // Initial buffer size
    size_t artist_length = 0;

    tmp1 = popen("cmus-remote -Q | grep 'tag artist' | sed s/'tag artist'/''/g | sed '1s/^.//'", "r");
    if (tmp1 == NULL) {
        fprintf(stderr, "Failed to run command\n");
        return 1;
    }

    artist = malloc(buffer_size * sizeof(char));
    if (artist == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return 1;
    }

    char buffer[128];
    while (fgets(buffer, sizeof(buffer), tmp1) != NULL) {
        size_t len = strlen(buffer);
        if (artist_length + len >= buffer_size) {
            buffer_size *= 2; // Double the buffer size if needed
            artist = realloc(artist, buffer_size * sizeof(char));
            if (artist == NULL) {
                fprintf(stderr, "Failed to reallocate memory\n");
                return 1;
            }
        }
        strcpy(artist + artist_length, buffer);
        artist_length += len;
    }

    pclose(tmp1);

    // Remove newline character if present
    if (artist[artist_length - 1] == '\n') {
        artist[artist_length - 1] = '\0';
    }

    // Print the result
    printf("Artist: %s\n", artist);

    // Free allocated memory
    free(artist);

    return 0;
}
