#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *tmp1;
    tmp1 = popen("cmus-remote -Q | grep 'tag artist' | sed s/'tag artist'/''/g | sed '1s/^.//'", "r");
    if (tmp1 == NULL) {
        printf("Error opening pipe!\n");
        return 1;
    }

    // Determine the size of the data in tmp1
    fseek(tmp1, 0, SEEK_END);
    long int size = ftell(tmp1);
    rewind(tmp1);

    // Allocate memory for artist
    char *artist = malloc(sizeof(char) * (size + 1));
    if (artist == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Read the contents of tmp1 into artist
    fread(artist, sizeof(char), size, tmp1);

    // Append null-terminator
    artist[size] = '\0';

    // Access the data in artist
    printf("Artist: %s\n", artist);

    // Free the allocated memory
    free(artist);

    // Close the pipe
    pclose(tmp1);

    return 0;
}
