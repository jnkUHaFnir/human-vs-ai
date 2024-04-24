#include <stdio.h>
#include <string.h>

#define MIN_ASCII_VALUE 97 // 'a'
#define MAX_ASCII_VALUE 122 // 'z'

int CHAR_OUT_OF_RANGE(char c) {
    return c < 'a' || c > 'z';
}

void vigenereEncrypt(const char plaintext[], char ciphertext[], const char key[]) {
    int idx;
    int j = 0;
    int keyLen = strlen(key);

    for (idx = 0; idx < strlen(plaintext); idx++) {
        if (CHAR_OUT_OF_RANGE(plaintext[idx])) {
            ciphertext[idx] = plaintext[idx];
        } else {
            ciphertext[idx] = ((plaintext[idx] - 'a') + (key[j % keyLen] - 'a')) % 26 + 'a';
            j++;
        }
    }

    ciphertext[idx] = '\0';
}

int main() {
    const char plaintext[] = "toner";
    const char key[] = "jerry";
    char ciphertext[100]; // Make sure this buffer is large enough

    vigenereEncrypt(plaintext, ciphertext, key);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
