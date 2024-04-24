#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* align_text(char* text) {
    int length = strlen(text);
    
    // If length is already 16 or more, return the original text
    if (length >= 16) {
        return text;
    }
    
    // Calculate the number of spaces needed to center the text
    int spaces = (16 - length) / 2;
    
    // Create a new string with the needed spaces and the input text
    char* centered_text = (char*)malloc(17 * sizeof(char));
    memset(centered_text, ' ', 16);
    centered_text[16] = '\0';
    strcpy(centered_text + spaces, text);
    
    return centered_text;
}

int main() {
    char* input_text = "Hello, world!";
    char* centered_text = align_text(input_text);
    
    printf("%s\n", centered_text);  // This should print the input text centered on a 16*8 screen
    
    free(centered_text);  // Don't forget to free the memory allocated for the centered text
    
    return 0;
}
