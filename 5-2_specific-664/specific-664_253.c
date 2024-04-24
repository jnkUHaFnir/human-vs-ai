#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

unsigned char* bit_encrypt(const char* text) {
    size_t text_length = strlen(text);
    char text_copy[text_length + 1]; // Include space for null terminator
    strcpy(text_copy, text);
    
    bool (*bits)[8] = malloc(text_length * sizeof *bits); // Dynamically allocate memory for bits array
    if(bits == NULL) {
        perror("Memory allocation for bits failed");
        return NULL;
    }
    
    int dec = 0;

    for(size_t i = 0; i < text_length; i++){
        dec = (int)text_copy[i];

        for(int j = 7; j >= 0; j--) {
            bits[i][j] = (dec & (1 << j)) ? true : false;
        }
    }

    for(size_t i = 0; i < text_length; i++){
        printf("%c:  ", text_copy[i]); 
        for(int j = 0; j < 8; j++){
            printf("%d ", bits[i][j]);
        }
        printf("\n");
    }

    int a = 53;
    printf("%d", a);

    // Free dynamically allocated memory
    free(bits);

    return NULL; // Return appropriate value
}

int main() {
    const char* input = "Hello world!";
    bit_encrypt(input);

    return 0;
}
