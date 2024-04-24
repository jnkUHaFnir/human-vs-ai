#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 1024

int main() {
    FILE *tmp1;
    char *artist = NULL;
    size_t artist_size = 0;
    size_t artist_len = 0;
    char chunk[CHUNK_SIZE];

    tmp1 = popen("cmus-remote -Q | grep 'tag artist' | sed s/'tag artist'/''/g | sed '1s/^.//'", "r");
    if (!tmp1) {
        perror("popen");
        return 1;
    }

    while (fgets(chunk, CHUNK_SIZE, tmp1) != NULL) {
        size_t chunk_len = strlen(chunk);
        char *new_artist = realloc(artist, artist_len + chunk_len + 1);

        if (new_artist == NULL) {
            fprintf(stderr, "Error: Memory allocation failed.\n");
            free(artist);
            pclose(tmp1);
            return 1;
        }

        artist = new_artist;
        strncpy(artist + artist_len, chunk, chunk_len);
        artist_len += chunk_len;
        artist[artist_len] = '\0';
    }

    printf("Artist: %s\n", artist);

    free(artist);
    pclose(tmp1);

    return 0;
}
