#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverse_string(const char *string) {
    int length = strlen(string);
    // Allocate memory for the reversed string + 1 for the null terminator.
    char* reversed = malloc(length + 1); 

    if (reversed == NULL) {
        // Handle malloc failure.
        perror("Failed to allocate memory for reversed string");
        return NULL;
    }

    for (int i = 0; i < length; i++) {
        reversed[i] = string[length - 1 - i];
    }
    reversed[length] = '\0'; // Null-terminate the reversed string.

    return reversed;
}

int main(int argc, char *argv[]){
    if (argc < 2) {
        fprintf(stderr, "Usage: %s string_to_reverse\n", argv[0]);
        return 1;
    }

    char* reversed = reverse_string(argv[1]);
    if (reversed != NULL) {
        puts(reversed);
        free(reversed); // Don't forget to free the allocated memory!
    }

    printf("This is the end of the program\n");
    return 0;
}
