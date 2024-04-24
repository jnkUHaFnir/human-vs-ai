#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *tmp1;
    char *artist = NULL;
    size_t artist_len = 0;
    size_t artist_size = 0;
    tmp1 = popen("cmus-remote -Q | grep 'tag artist' | sed s/'tag artist'/''/g | sed '1s/^.//'", "r");

    if (tmp1 == NULL) {
        fprintf(stderr, "Error opening pipe.\n");
        return 1;
    }

    char buffer[256]; // Buffer to read lines from the pipe
    while (fgets(buffer, sizeof(buffer), tmp1) != NULL) {
        artist_len += strlen(buffer);
        if (artist_len >= artist_size) {
            artist_size = artist_size == 0 ? artist_len : artist_size * 2;
            artist = realloc(artist, artist_size);
            if (artist == NULL) {
                fprintf(stderr, "Memory allocation error.\n");
                return 1;
            }
        }
        strcat(artist, buffer);
    }

    pclose(tmp1); // Close the pipe

    // Use the artist string here

    printf("Artist: %s\n", artist);

    free(artist); // Free the dynamically allocated memory

    return 0;
}
