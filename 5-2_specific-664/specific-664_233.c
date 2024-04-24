#include <stdio.h>
#include <string.h>

#define MIN_ASCII_VALUE 97 // ASCII value for 'a'
#define MAX_ASCII_VALUE 122 // ASCII value for 'z'

void vigenereEncrypt(const char plaintext[], char ciphertext[], const char key[])
{
    int idx;
    int j;

    int plaintextLen = strlen(plaintext);
    int keyLen = strlen(key);

    for (idx = 0, j = 0; idx < plaintextLen; idx++)
    {
        if (plaintext[idx] < 'a' || plaintext[idx] > 'z')
        {
            ciphertext[idx] = plaintext[idx];
        }
        else
        {
            int shift = key[j] - 'a'; // Calculate the shift based on the key

            char encryptedChar = plaintext[idx] + shift;

            if (encryptedChar > 'z') // Wrap around if encryptedChar exceeds 'z'
            {
                encryptedChar = 'a' + (encryptedChar - 'z' - 1);
            }

            ciphertext[idx] = encryptedChar;
        }

        j = (j + 1) % keyLen;
    }

    ciphertext[plaintextLen] = '\0';
}

int main()
{
    const char plaintext[] = "toner";
    char ciphertext[6]; // Make sure to adjust the size of the array accordingly
    const char key[] = "jerry";

    vigenereEncrypt(plaintext, ciphertext, key);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
