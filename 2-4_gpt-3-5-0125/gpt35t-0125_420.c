#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* flip_string(char *string){
    int i = strlen(string)-1;
    int j = 0;

    // Create a new string to store the flipped string
    char* temp = malloc(strlen(string) + 1);

    for(i; i>=0; i--){
        temp[j] = string[i];
        j++;
    }
    temp[j] = '\0'; // Add null character at the end

    return temp;
}

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    char *flipped = flip_string(argv[1]);
    printf("Flipped string: %s\n", flipped);
    
    // Free the memory allocated for flipped string
    free(flipped);

    printf("This is the end of the program\n");

    return 0;
}
