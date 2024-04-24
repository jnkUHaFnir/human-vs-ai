#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* flip_string(const char *string){
    int length = strlen(string);
    char* temp = malloc(length + 1); // Allocate memory for the temporary string

    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Copy the original string to temp
    strcpy(temp, string);

    int i, j;
    for(i = length-1, j = 0; i>=0; i--, j++){
        temp[j] = string[i];
    }

    temp[length] = '\0'; // Add null terminator

    return temp;
}

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Usage: %s <input_string>\n", argv[0]);
        return 1;
    }

    char* reversed_string = flip_string(argv[1]);
    printf("Reversed string: %s\n", reversed_string);
    
    // Free allocated memory
    free(reversed_string);

    return 0;
}
