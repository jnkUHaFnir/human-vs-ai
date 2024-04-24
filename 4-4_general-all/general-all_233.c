#include <stdio.h>
#include <string.h>

#define MIN_ASCII_VALUE 97 // 'a'
#define MAX_ASCII_VALUE 122 // 'z'

void vigenereEncrypt(const char plaintext[], char ciphertext[], const char key[]) {

    int idx;
    int j = 0;
    int keyLength = strlen(key);

    for (idx = 0; plaintext[idx] != '\0'; idx++) {
        if (plaintext[idx] < 'a' || plaintext[idx] > 'z') {
            ciphertext[idx] = plaintext[idx];
        } else {
            int shift = key[j % keyLength] - 'a'; // Calculate the shift based on the key

            char encryptedChar = plaintext[idx] + shift;
            if (encryptedChar > 'z') {
                encryptedChar = 'a' + (encryptedChar - 'z' - 1);
            }

            ciphertext[idx] = encryptedChar;
            j++;
        }
    }

    ciphertext[idx] = '\0';
}

int main() {
    const char plaintext[] = "toner";
    char ciphertext[6]; // Make sure to have enough space for the null terminator
    const char key[] = "jerry";

    vigenereEncrypt(plaintext, ciphertext, key);

    printf("Ciphertext: %s\n", ciphertext);
    
    return 0;
}
