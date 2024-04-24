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

    int key = atoi(argv[1]); // Convert the key from string to integer

    // Validate the key
    if (key < 0)
    {
        printf("Key must be a non-negative integer.\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    if (!plaintext)
    {
        return 1;
    }

    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            char rotated = ((c - base + key) % 26) + base;
            printf("%c", rotated);
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");

    return 0;
}
