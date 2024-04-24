#include <stdio.h>
#include <string.h>

#define MIN_ASCII_VALUE 97 // 'a'
#define MAX_ASCII_VALUE 122 // 'z'

void vigenereEncrypt(const char plaintext[], char ciphertext[], const char key[])
{
    int idx;
    int j;

    for (idx = 0, j = 0; idx < strlen(plaintext); idx++)
    {
        if (CHAR_OUT_OF_RANGE(plaintext[idx]))
        {
            ciphertext[idx] = plaintext[idx];
        }
        else
        {
            ciphertext[idx] = plaintext[idx] + (key[j] - 'a');

            if (ciphertext[idx] > MAX_ASCII_VALUE)
            {
                ciphertext[idx] -= 26; // Wrap around if exceeding 'z'
            }
        }
        j = (j + 1) % strlen(key);
    }

    ciphertext[idx] = '\0';
}

int main()
{
    const char plaintext[] = "toner";
    char ciphertext[10]; // Make sure it's large enough to hold the result
    const char key[] = "jerry";

    vigenereEncrypt(plaintext, ciphertext, key);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
