#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{                
    if (argc == 2)
    {
        for(int k = 0; k <strlen(argv[1]); k++)
        {
            if (!isdigit(argv[1][k]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }   

        int key = atoi(argv[1]) % 26;  // Ensure key is within the range of 0-25

        string s = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int i = 0; i < strlen(s); i++)
        {
            char c = s[i];

            if (isalpha(c))
            {
                char base = isupper(c) ? 'A' : 'a';
                c = (c - base + key) % 26 + base;
            }

            printf("%c", c);
        }
        printf("\n");
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    return 0;
}
