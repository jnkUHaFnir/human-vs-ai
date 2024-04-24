#include <cs50.h>    // If you're not using CS50 library, you'll need to replace get_string with standard input methods
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

    // Check if the argument is all digits
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert argv[1] to an integer
    int key = atoi(argv[1]);

    // Get plaintext from user
    string s = get_string("plaintext: ");

    printf("ciphertext: ");

    // Iterate over each character of the plaintext
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]))
        {
            // Preserve case
            char base = islower(s[i]) ? 'a' : 'A';
            // Shift the character and wrap around using modulo
            printf("%c", (s[i] - base + key) % 26 + base);
        }
        else
        {
            // Non-alphabetical characters are printed as is
            printf("%c", s[i]);
        }
    }

    printf("\n");
    // No need to free(s) since get_string doesn't require manual memory management in CS50's library

    return 0;
}
