#include <stdio.h>
#include <stdlib.h>

char* readFromPipe(FILE* fp) {
    char* buffer = NULL;
    size_t bufferSize = 0;
    size_t bytesRead;

    // Read from the FILE * into a dynamically allocated buffer
    while ((bytesRead = getline(&buffer, &bufferSize, fp)) != -1) {
        // Check if the line read is the one you are interested in, e.g., 'tag artist'
        // You may need to customize this part based on your specific requirements
        if (/* condition to check */ ) {
            // Perform operations if needed
        }
    }

    return buffer;
}

int main() {
    FILE *tmp1;
    char *artist;

    tmp1 = popen("cmus-remote -Q | grep 'tag artist' | sed s/'tag artist'/''/g | sed '1s/^.//'", "r");
    
    if (tmp1 == NULL) {
        printf("Error opening pipe.\n");
        return 1;
    }

    artist = readFromPipe(tmp1);

    // Close the pipe
    pclose(tmp1);

    // Use the 'artist' string as needed

    // Don't forget to free the dynamically allocated memory when done
    free(artist);

    return 0;
}
