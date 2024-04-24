#include <stdio.h>
#include <stdbool.h>
#include <string.h>

unsigned char* bit_encrypt(const char* text) {
    char text_copy[strlen(text)];
    printf("Strlen: %ld\n", strlen(text));
  
    // Calculate the number of characters in the input text
    int text_length = strlen(text);
    
    bool bits[text_length][8];

    for(int i = 0; i < text_length; i++){
        text_copy[i] = text[i];
        int dec = (int) text_copy[i];
        int j = 7; // Start filling bits from the most significant bit

        // Fill the bits array with the binary representation of the character
        for(int k = 0; k < 8; k++){
            bits[i][j--] = dec % 2;
            dec = dec / 2;
        }
    }
    
    // Print the binary representation of each character
    for(int i = 0; i < text_length; i++){
        printf("%c:  ", text_copy[i]); 
        for(int j = 0; j < 8; j++){
            printf("%d ", bits[i][j]);
        }
        printf("\n");
    }

    // int a = 53;
    // printf("%d", a);

    // This part of code was commented out as it caused the segmentation fault
    // You need to properly allocate and return a value at the end of the function
    // Uncomment and modify this part as necessary for your use case

    // unsigned char* vystup = (unsigned char*)calloc(text_length, sizeof(unsigned char));
    // return vystup;

    return NULL;
}

int main() {
    const char* input = "Hello world!";
    bit_encrypt(input);
    return 0;
}
