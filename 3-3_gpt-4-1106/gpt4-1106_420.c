#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* flip_string(const char *string) {
    int i = strlen(string);
    int j = 0;

    // Allocate new space for the reversed string, including the null terminator.
    char* temp = (char*)malloc(i + 1);
    if (!temp) {
        // Handle memory allocation failure.
        fprintf(stderr, "Memory allocation error.\n");
        return NULL;
    }

    puts("This is the original string:");
    puts(string);

    for(i = i - 1; i >= 0; i--) {
        temp[j++] = string[i];
    }

    // Null-terminate the reversed string.
    temp[j] = '\0';

    puts("This is the reversed string:");
    puts(temp);

    // Remember that the calling code is now responsible for freeing `temp`.
    return temp;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the reversed string.
    char *reversed = flip_string(argv[1]);
    if (reversed) {
        puts(reversed);
        free(reversed);  // Free the memory allocated by flip_string.
    }
    
    printf("This is the end of the program\n");
    return EXIT_SUCCESS;
}
