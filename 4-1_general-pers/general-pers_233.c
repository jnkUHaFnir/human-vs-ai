#include <stdio.h>
#include <string.h>

#define MIN_ASCII_VALUE 97 // 'a'
#define MAX_ASCII_VALUE 122 // 'z'

int isLowercaseChar(char c) {
    return (c >= 'a' && c <= 'z');
}

char vigenereEncryptChar(char plaintext, char key) {
    if (!isLowercaseChar(plaintext)) {
        return plaintext;
    }

    return ((plaintext - MIN_ASCII_VALUE + key - MIN_ASCII_VALUE) % 26) + MIN_ASCII_VALUE;
}

void vigenereEncrypt(const char plaintext[], char ciphertext[], const char key[]) {
    size_t idx;
    size_t keyLen = strlen(key);

    for (idx = 0; idx < strlen(plaintext); idx++) {
        ciphertext[idx] = vigenereEncryptChar(plaintext[idx], key[idx % keyLen]);
    }

    ciphertext[idx] = '\0';
}

int main() {
    const char plaintext[] = "toner";
    const char key[] = "jerry";
    char ciphertext[strlen(plaintext)];

    vigenereEncrypt(plaintext, ciphertext, key);

    printf("Plaintext: %s\n", plaintext);
    printf("Key: %s\n", key);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
