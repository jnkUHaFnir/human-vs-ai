#include <stdio.h>
#include <string.h>

#define MIN_ASCII_VALUE 97 // ASCII value of 'a'
#define MAX_ASCII_VALUE 122 // ASCII value of 'z'

// Function to check if character is out of range (not lowercase letter)
int CHAR_OUT_OF_RANGE(char c) {
    return (c < 'a' || c > 'z');
}

void vigenereEncrypt(const char plaintext[], char ciphertext[], const char key[]) {
    size_t plaintext_len = strlen(plaintext);
    size_t key_len = strlen(key);
    
    for (size_t idx = 0, j = 0; idx < plaintext_len; idx++) {
        if (CHAR_OUT_OF_RANGE(plaintext[idx])) {
            ciphertext[idx] = plaintext[idx];
        } else {
            char base = (islower(plaintext[idx])) ? 'a' : 'A';
            char offset = islower(plaintext[idx]) ? 'a' : 'A';
            
            ciphertext[idx] = ((plaintext[idx] - base + key[j] - offset) % 26) + base;
            j = (j + 1) % key_len;
        }
    }

    ciphertext[plaintext_len] = '\0';
}

int main() {
    const char plaintext[] = "toner";
    const char key[] = "jerry";
    char ciphertext[6]; // Make sure to adjust this based on the size of your plaintext

    vigenereEncrypt(plaintext, ciphertext, key);
    printf("Encrypted text: %s\n", ciphertext);

    return 0;
}
