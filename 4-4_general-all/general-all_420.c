#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* flip_string(const char *string){
    int i = strlen(string) - 1;
    int j = 0;
    
    char* temp = malloc(strlen(string) + 1); // Allocate memory for the reversed string
    if (temp == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    puts("This is the original string");
    puts(string);

    for(; i>=0; i--){
        temp[j] = string[i];
        j++;
    }
    temp[j] = '\0'; // Add null terminator to the end of the reversed string

    return temp;
}

int main(int argc, char *argv[]){
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char* reversedString = flip_string(argv[1]);
    if(reversedString != NULL) {
        printf("Reversed string: %s\n", reversedString);
        free(reversedString); // Free the allocated memory
    }
    
    printf("This is the end of the program\n");

    return EXIT_SUCCESS;
}
