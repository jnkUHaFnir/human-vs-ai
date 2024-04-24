#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* global;

int main () {
    printf("Please Enter Text: \n");
    
    // Allocate memory for the string
    global = (char*)malloc(sizeof(char) * 100); // Allocating memory for 100 characters
    
    // Read the input sentence
    fgets(global, 100, stdin); // Using fgets to read the whole sentence
    
    // Print out the sentence
    printf("%s", global);

    // Free the allocated memory
    free(global);

    return 0;
}
