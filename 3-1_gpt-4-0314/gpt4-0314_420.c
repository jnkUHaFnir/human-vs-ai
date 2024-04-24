#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* flip_string(char *string){
    int len = strlen(string);
    char* temp = malloc(len+1); // Allocate memory for the temp string

    int i = len - 1; // Start from the last character of the original string
    int j = 0;

    puts("This is the original string:");
    puts(string);
    puts("This is the reversed string:");

    for(; i>=0; i--){
        temp[j++] = string[i];
    }
    temp[j] = '\0'; // Add null terminator to the end of the temp string

    return(temp);
}

int main(int argc, char *argv[]){
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }
    char *reversed_str = flip_string(argv[1]);
    puts(reversed_str);
    free(reversed_str); // Don't forget to free the allocated memory
    printf("This is the end of the program\n");
}
