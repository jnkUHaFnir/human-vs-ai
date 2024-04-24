#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    int counter = 0;
    if (argc == 2)
    {
        for(int k = 0; k <strlen(argv[1]); k++)
        {
            if (isdigit(argv[1][k]))
            {
                counter++;
            }
        }
        if (strlen(argv[1]) == counter)
        {
            int key = atoi(argv[1]); // Convert the key to an integer
            string s = get_string("plaintext: ");
            if(s)
            {
                printf("ciphertext: ");
                for (int i = 0; i < strlen(s); i++)
                {
                    char c = s[i];
                    if (isalpha(c))
                    {
                        char base = islower(c) ? 'a' : 'A'; // Determines whether the character is uppercase or lowercase
                        printf("%c", (((c - base) + key) % 26) + base); // Rotates the character by the given key
                    }
                    else
                    {
                        printf("%c", c);
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
    }
    else
    {
        printf("Usage: ./caesar key\n");
    }
}
