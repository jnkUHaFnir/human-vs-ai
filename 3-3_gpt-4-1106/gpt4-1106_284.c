#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Check for correct number of arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1; // Return a non-zero value indicating error
    }

    // Check if the argv[1] only contains digits and convert to integer
    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1; // Return error if the key isn't a number
        }
    }
    
    // Convert the key from a string to an int
    int key = atoi(argv[1]);
    
    // Prompt user for plaintext
    string plaintext = get_string("plaintext: ");
    
    printf("ciphertext: ");
    
    // Iterate over each character in the plaintext
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        // Only cipher alphabetical characters
        if (isalpha(plaintext[i]))
        {
            // Preserve case
            if (isupper(plaintext[i]))
            {
                // Rotate letter by key and maintain uppercase
                printf("%c", 'A' + (plaintext[i] - 'A' + key) % 26);
            }
            else // islower(plaintext[i])
            {
                // Rotate letter by key and maintain lowercase
                printf("%c", 'a' + (plaintext[i] - 'a' + key) % 26);
            }
        }
        else
        {
            // Directly print the non-alphabetic character
            printf("%c", plaintext[i]);
        }
    }
    
    // Print the newline character after the output
    printf("\n");
    
    return 0; // Successful termination
}
