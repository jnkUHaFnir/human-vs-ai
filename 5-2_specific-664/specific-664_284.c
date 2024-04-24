#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{                
    if (argc == 2)
    {
        int key = atoi(argv[1]); // Convert key input to an integer
        string plain_text = get_string("plaintext: ");
        if (plain_text)
        {
            printf("ciphertext: ");
            for (int i = 0, n = strlen(plain_text); i < n; i++)
            {
                if (isalpha(plain_text[i]))
                {
                    char base = islower(plain_text[i]) ? 'a' : 'A';
                    char rotated_char = ((plain_text[i] - base + key) % 26) + base;
                    printf("%c", rotated_char);
                }
                else
                {
                    printf("%c", plain_text[i]); // Print non-alphabetic characters as is
                }
            }
            printf("\n");
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
    }

    return 0;
}
