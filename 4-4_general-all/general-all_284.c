#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    // Validate key as a number
    if (key == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    char plaintext[100]; // Assuming a maximum input of 100 characters
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        char c = plaintext[i];

        if (isalpha(c))
        {
            char base = islower(c) ? 'a' : 'A';
            printf("%c", (c - base + key) % 26 + base);
        }
        else
        {
            printf("%c", c); // Non-alphabetic characters remain unchanged
        }
    }

    printf("\n");

    return 0;
}
