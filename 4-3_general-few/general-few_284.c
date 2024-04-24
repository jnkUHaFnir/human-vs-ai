#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{                
    if (argc == 2)
    {
        // Check if key is a number
        int counter = 0;
        for (int k = 0; k < strlen(argv[1]); k++)
        {
            if (isdigit(argv[1][k]))
            {
                counter++;
            }
        }

        if (strlen(argv[1]) == counter)
        {
            // Convert key to an integer
            int key = atoi(argv[1]);

            string s = get_string("plaintext: ");
            if (s)
            {
                printf("ciphertext: ");
                for (int i = 0, n = strlen(s); i < n; i++)
                {
                    char c = s[i];
                    if (isalpha(c))
                    {
                        char base = islower(c) ? 'a' : 'A';
                        char rotated_char = (c - base + key) % 26 + base;
                        printf("%c", rotated_char);
                    }
                    else
                    {
                        printf("%c", c); // Non-alphabet characters remain unchanged
                    }
                }
                printf("\n");
            }
        }
        else
        {
            printf("Usage: ./caesar key\n");
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
    }

    return 0;                     
}
