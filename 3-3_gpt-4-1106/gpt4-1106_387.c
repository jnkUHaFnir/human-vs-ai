#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_BUFFER_SIZE 1024

int main() {
    FILE *tmp1;
    char *artist = NULL;
    size_t buffer_size = 0;
    size_t used_size = 0;
    char buffer[INITIAL_BUFFER_SIZE];  // Used to read data in chunks.

    tmp1 = popen("cmus-remote -Q | grep 'tag artist' | sed s/'tag artist'/''/g | sed '1s/^.//'", "r");

    if (tmp1 == NULL) {
        perror("popen failed");
        return EXIT_FAILURE;
    }

    // Read the output of the popen in chunks.
    while (fgets(buffer, sizeof(buffer), tmp1) != NULL) {
        size_t chunk_size = strlen(buffer);
        if (used_size + chunk_size + 1 > buffer_size) {
            // Need to increase buffer size. Reallocate with a larger buffer.
            size_t new_buffer_size = buffer_size == 0 ? INITIAL_BUFFER_SIZE : buffer_size * 2;
            char *new_artist = realloc(artist, new_buffer_size);
            if (new_artist == NULL) {
                perror("Out of memory");
                free(artist);
                pclose(tmp1);
                return EXIT_FAILURE;
            }
            artist = new_artist;
            buffer_size = new_buffer_size;
        }
        memcpy(artist + used_size, buffer, chunk_size);
        used_size += chunk_size;
    }

    if (artist != NULL) {
        artist[used_size] = '\0';  // Null-terminate the string.
    }

    // Don't forget to handle the error case if fgets failed.
    if (ferror(tmp1)) {
        perror("Error reading from pipe");
        free(artist);
        pclose(tmp1);
        return EXIT_FAILURE;
    }

    // Print the artist name (for demonstration purposes)
    printf("Artist: %s\n", artist);

    // Clean up: close the popen stream and free the allocated memory.
    pclose(tmp1);
    free(artist);

    return EXIT_SUCCESS;
}
