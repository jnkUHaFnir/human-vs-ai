#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* flip_string(char *string){
    int len = strlen(string);
    char* temp = malloc(len + 1); // Allocating memory for the new string
    int i, j;

    for(i = len - 1, j = 0; i>=0; i--, j++){ 
        temp[j] = string[i];
    }
    
    temp[j] = '\0'; // Null-terminating the string
    
    return temp;
}

int main(int argc, char *argv[]){
    if(argc < 2) { // If no arguments are provided, exit
        printf("You should provide a string as argument.\n");
        return 1;
    }
    char* flipped = flip_string(argv[1]);
    printf("%s\n", flipped);
    free(flipped); // Don't forget to deallocate the memory after use
    printf("This is the end of the program\n");
    return 0;
}
