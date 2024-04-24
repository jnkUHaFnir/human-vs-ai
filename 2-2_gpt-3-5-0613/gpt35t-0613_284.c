#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string key = argv[1];
        for (int i = 0; i < strlen(key); i++)
        {
            if (!isdigit(key[i]))
            {
                printf("Key must be a number\n");
                return 1;
            }
        }
        
        int k = atoi(key); // Convert string key to an integer
        
        string plaintext = get_string("plaintext: ");
        int length = strlen(plaintext);
        char ciphertext[length];
        
        for (int i = 0; i < length; i++)
        {
            if (isalpha(plaintext[i]))
            {
                char base = isupper(plaintext[i]) ? 'A' : 'a';
                ciphertext[i] = (plaintext[i] - base + k) % 26 + base;  // Rotate character by key
            }
            else
            {
                ciphertext[i] = plaintext[i]; // Pass non-alphabetic characters unchanged
            }
        }
        
        printf("ciphertext: %s\n", ciphertext);
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    return 0;
}
