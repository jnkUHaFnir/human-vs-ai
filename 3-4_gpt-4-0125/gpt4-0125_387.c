#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *tmp1;
    char *artist = NULL;
    // Assume you'll never have a line longer than this for simplicity,
    // but this could be made dynamic as well.
    char buffer[1024];
    
    // Adjust the command as necessary
    tmp1 = popen("cmus-remote -Q | grep 'tag artist' | sed s/'tag artist'/''/g | sed '1s/^.//'", "r");
    
    if (tmp1 == NULL) {
        fprintf(stderr, "Failed to run command\n" );
        exit(1);
    }

    size_t length = 0;
    while (fgets(buffer, sizeof(buffer), tmp1) != NULL) {
        size_t new_line_length = strlen(buffer);
        char *temp = realloc(artist, length + new_line_length + 1); // +1 for '\0'
        if(temp == NULL) {
            perror("realloc failed");
            free(artist);
            exit(EXIT_FAILURE);
        }
        artist = temp;
        
        // Adding the new string
        memcpy(artist + length, buffer, new_line_length);
        length += new_line_length;
    }
    
    if (artist != NULL) {
        artist[length] = '\0'; // Ensure null-terminating
        printf("Artist: %s\n", artist);
        free(artist); // Don't forget to free the memory
    }

    pclose(tmp1);
    
    return 0;
}
