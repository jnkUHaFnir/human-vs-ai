#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* flip_string(char *string) {
    int length = strlen(string);
    char* temp = (char*)malloc((length + 1) * sizeof(char)); // Allocate memory for temp string

    for(int i = 0; i < length; i++) {
        temp[i] = string[length - 1 - i];
    }
    temp[length] = '\0'; // Add null terminator

    return temp;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [string]\n", argv[0]);
        return 1;
    }

    char* reversed = flip_string(argv[1]);
    printf("Reversed string: %s\n", reversed);

    free(reversed); // Free allocated memory for reversed

    printf("This is the end of the program\n");

    return 0;
}
