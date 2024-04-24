#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{                
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Read the key as an integer
    int key = atoi(argv[1]);

    string plaintext = get_string("plaintext: ");
    if (plaintext == NULL)
    {
        return 1;
    }

    // Iterate through each character of the plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // Rotate alphabetic characters by the key, preserving case
        if (isalpha(plaintext[i]))
        {
            char start = islower(plaintext[i]) ? 'a' : 'A';
            plaintext[i] = start + (plaintext[i] - start + key) % 26;
        }
    }

    // Print the resulting ciphertext
    printf("ciphertext: %s\n", plaintext);

    // Free the input string
    free(plaintext);

    return 0;
}
plaintext[i] = start + (plaintext[i] - start + key) % 26;
