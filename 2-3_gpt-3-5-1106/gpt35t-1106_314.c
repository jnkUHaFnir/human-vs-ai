#include <stdio.h>

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    unsigned int num = n[0] + n[1]*256 + n[2]*256*256; // Convert from base 256 to base 10

    char buffer[20]; // Buffer to hold the string representation of the number
    sprintf(buffer, "%d", num); // Convert the number to a string in base 10

    printf("%s\n", buffer); // Print the string
    return 0;
}
