#include <stdio.h>

int main() {
    unsigned char n[] = {1, 2, 3}; // Note the correct variable name 'n' instead of 'char'
    int num = 0;

    // Convert the unsigned char array to a base 10 integer
    for (int i = 0; i < sizeof(n); i++) {
        num = num * 256 + n[i];
    }

    // Format the integer as a string in base 10
    char buffer[20]; // Make sure the buffer is large enough to hold the string representation of the number
    sprintf(buffer, "%d", num);

    // Print the string
    printf("%s\n", buffer);

    return 0;
}
