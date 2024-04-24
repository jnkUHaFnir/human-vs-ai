#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* flip_string(char *string){
    int i = strlen(string) - 1;
    int j = 0;

    char* temp = malloc(strlen(string) + 1); // Allocate memory for temp
    temp[strlen(string)] = '\0';

    for(; i >= 0; i--){
        temp[j] = string[i];
        j++;
    }

    return temp;
}

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    char* reversed = flip_string(argv[1]);
    printf("Reversed string: %s\n", reversed);
    
    free(reversed); // Free the memory allocated for reversed
    printf("This is the end of the program\n");
    
    return 0;
}
