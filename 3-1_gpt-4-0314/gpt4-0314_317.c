#include <stdio.h>
#include <string.h>

void printBase10(unsigned char n[], int size)
{
    char result[500] = {0}; // Assumes the resulting decimal number is less than 500 digits

    // Step 2
    for (int i = 0; i < size; i++)
    {
        int carry = n[i];

        // Step 2b
        for (int j = strlen(result) - 1; j >= 0; j--)
        {
            int digit = result[j] - '0'; // Convert character to integer
            carry += digit * 256;
            result[j] = (carry % 10) + '0'; // Convert integer to character
            carry /= 10;
        }

        // Step 2c
        while (carry)
        {
            memmove(result + 1, result, strlen(result) + 1); // Shift string one place to the right
            result[0] = (carry % 10) + '0';
            carry /= 10;
        }
    }

    // Step 3
    printf("%s\n", result);
}

int main()
{
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    printBase10(n, 3);

    return 0;
}
