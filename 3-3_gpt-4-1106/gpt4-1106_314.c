#include <stdio.h>
#include <string.h>

// Assume maximum size of the base 10 buffer
#define MAX_SIZE 400

// Function to multiply our base-10 buffer by 256
void multiply_by_256(unsigned int *buffer, int size) {
    for(int i = 0; i < 8; i++) {
        unsigned int carry = 0;
        for(int j = 0; j < size; j++) {
            unsigned int value = buffer[j] * 2 + carry;
            buffer[j] = value % 10;
            carry = value / 10;
        }
    }
}

// Function to add an unsigned char to our base-10 buffer
void add_to_buffer(unsigned int *buffer, unsigned char value, int size) {
    unsigned int carry = value;
    for(int i = 0; carry > 0 && i < size; i++) {
        unsigned int sum = buffer[i] + carry;
        buffer[i] = sum % 10;
        carry = sum / 10;
    }
}

int main() {
    unsigned char n[100] = {0}; // For example, set this with your byte array values
    unsigned int decimal_buffer[MAX_SIZE] = {0}; // Initialize base-10 buffer to zero

    // Populate `n` for demonstration purposes
    n[97] = 1;
    n[98] = 2;
    n[99] = 3;

    // Process the byte array and calculate the base-10 value
    for(int i = 0; i < sizeof(n); i++) {
        multiply_by_256(decimal_buffer, MAX_SIZE);
        add_to_buffer(decimal_buffer, n[i], MAX_SIZE);
    }

    // Find the start of the non-zero buffer and print the number
    int start = MAX_SIZE - 1;
    while(start >= 0 && decimal_buffer[start] == 0) {
        --start;
    }

    if(start < 0) {
        printf("0\n"); // The number is zero
    } else {
        // Print the result in base 10
        for(int i = start; i >= 0; --i) {
            printf("%u", decimal_buffer[i]);
        }
        printf("\n");
    }

    return 0;
}
