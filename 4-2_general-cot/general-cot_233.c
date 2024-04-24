#include <stdio.h>
#include <string.h>

#define MIN_ASCII_VALUE 97 // 'a'
#define MAX_ASCII_VALUE 122 // 'z'

int CHAR_OUT_OF_RANGE(char ch) {
    return (ch < 'a' || ch > 'z');
}

void vigenereEncrypt(const char plaintext[], char ciphertext[], const char key[]) {
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
            ciphertext[idx] = (plaintext[idx] - 'a' + key[j] - 'a') % 26 + 'a';
            j = (j + 1) % strlen(key);
        }
    }

    ciphertext[idx] = '\0'; // Add null terminator at the end of the ciphertext
}

int main() {
    const char plaintext[] = "toner";
    char ciphertext[6]; // Length should be at least strlen(plaintext) + 1
    const char key[] = "jerry";

    vigenereEncrypt(plaintext, ciphertext, key);
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
