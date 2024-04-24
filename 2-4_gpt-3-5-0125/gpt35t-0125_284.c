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

    string key = argv[1];
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isdigit(key[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int k = atoi(key) % 26;

    string s = get_string("plaintext: ");
    if (!s)
    {
        return 1;
    }

    printf("ciphertext: ");
    for (int i = 0; i < strlen(s); i++)
    {
        char c = s[i];

        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base + k) % 26 + base;
        }

        printf("%c", c);
    }
    printf("\n");

    return 0;
}
