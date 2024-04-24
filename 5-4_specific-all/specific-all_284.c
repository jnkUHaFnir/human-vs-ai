#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{                
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]) % 26; // Ensuring key wraps around if it exceeds 26
    string plaintext = get_string("plaintext: ");
    if (!plaintext)
    {
        printf("Error getting plaintext.\n");
        return 1;
    }

    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char rotatedChar = plaintext[i];
        if (isalpha(plaintext[i]))
        {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            rotatedChar = (plaintext[i] - base + key) % 26 + base; // Rotate character
        }
        printf("%c", rotatedChar);
    }
    
    printf("\n");

    return 0;
}
