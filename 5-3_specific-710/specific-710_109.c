#include <stdio.h>

// Function to convert integer to binary string
const char *int_to_bin(int num)
{
    static char bin_str[9]; // Assuming 8-bit binary representation
    
    for (int i = 7; i >= 0; i--)
    {
        bin_str[7 - i] = ((num >> i) & 1) ? '1' : '0';
    }
    bin_str[8] = '\0'; // Null terminator
    
    return bin_str;
}

int main()
{
    char a = 5;
    
    printf("Binary representation of a = %s\n", int_to_bin(a));
    
    return 0;
}
