#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 1024

int main() {
    FILE *tmp1;
    char *artist = NULL;
    size_t artist_size = 0;
    
    tmp1 = popen("cmus-remote -Q | grep 'tag artist' | sed s/'tag artist'/''/g | sed '1s/^.//'", "r");

    if (tmp1 == NULL) {
        fprintf(stderr, "Error opening pipe\n");
        return 1;
    }

    char chunk[CHUNK_SIZE];
    size_t total_read = 0;

    while (fgets(chunk, CHUNK_SIZE, tmp1) != NULL) {
        size_t chunk_len = strlen(chunk);
        
        artist = realloc(artist, artist_size + chunk_len + 1);
        if (artist == NULL) {
            fprintf(stderr, "Error allocating memory\n");
            return 1;
        }

        strcpy(artist + total_read, chunk);
        total_read += chunk_len;
        artist_size += chunk_len;
    }

    pclose(tmp1);

    // Don't forget to add a null terminator at the end of the string
    artist[artist_size] = '\0';

    printf("Artist: %s\n", artist);
    
    // Do something with artist here
    
    free(artist); // Don't forget to free the memory allocated

    return 0;
}
