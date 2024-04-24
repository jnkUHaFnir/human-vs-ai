#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_ASCII_VALUE 97  // ASCII value for 'a'
#define MAX_ASCII_VALUE 122 // ASCII value for 'z'

int CHAR_OUT_OF_RANGE(char c) {
    return !(c >= 'a' && c <= 'z');
}

void vigenereEncrypt(const char plaintext[], char ciphertext[], const char key[]) {
    int idx;
    int j;

    int keyLength = strlen(key);

    for (idx = 0, j = 0; idx < strlen(plaintext); idx++) {
        if (CHAR_OUT_OF_RANGE(plaintext[idx])) {
            ciphertext[idx] = plaintext[idx];
        } else {
            char offset = islower(plaintext[idx]) ? 'a' : 'A'; // Adjust for case
            ciphertext[idx] = ((plaintext[idx] - offset + (tolower(key[j % keyLength]) - 'a')) % 26) + offset;
            j++;
        }
    }

    ciphertext[idx] = 0; // Add null terminator
}

int main() {
    const char plaintext[] = "toner";
    char ciphertext[6]; // Make sure it can hold the encrypted text
    const char key[] = "jerry";

    vigenereEncrypt(plaintext, ciphertext, key);
    printf("Cipher text: %s\n", ciphertext);

    return 0;
}
