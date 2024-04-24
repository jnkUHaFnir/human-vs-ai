#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int key = atoi(argv[1]) % 26; // Ensure key is within the range 0-25
        
        string s = get_string("plaintext: ");
        if (s)
        {
            printf("ciphertext: ");
            for (int i = 0, n = strlen(s); i < n; i++)
            {
                if (isalpha(s[i]))
                {
                    char base = isupper(s[i]) ? 'A' : 'a';
                    char rotated = (s[i] - base + key) % 26 + base;
                    printf("%c", rotated);
                }
                else
                {
                    printf("%c", s[i]); // Preserve non-alphabetic characters
                }
            }
            printf("\n");

            free(s);
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
    }

    return 0;
}
