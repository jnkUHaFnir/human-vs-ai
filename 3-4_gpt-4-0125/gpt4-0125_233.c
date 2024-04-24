#include <string.h>

void vigenereEncrypt(const char plaintext[], char ciphertext[], const char key[]) {
    int idx, j;

    for (idx = 0, j = 0; plaintext[idx] != '\0'; idx++) { // Change the loop condition here.
        if (plaintext[idx] < 'a' || plaintext[idx] > 'z') { // Assuming we're only dealing with lowercase for simplicity.
            ciphertext[idx] = plaintext[idx];
        } else {
            // Normalize to 0-25 range before performing the shift.
            int plainChar = plaintext[idx] - 'a';
            int keyChar = key[j % strlen(key)] - 'a'; // Use modulo on key length for wrap around.
            
            // Perform the encryption, ensuring to wrap correctly within the alphabet.
            ciphertext[idx] = (plainChar + keyChar) % 26 + 'a';
            
            j++; // Only increment j when a letter is encrypted.
        }
    }
    ciphertext[idx] = '\0'; // Ensure string is null-terminated.
}
