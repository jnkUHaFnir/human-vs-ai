#define MIN_ASCII_VALUE 97
#define MAX_ASCII_VALUE 122

void vigenereEncrypt(const char plaintext[], char ciphertext[], const char key[])
{
    int idx;
    int j;

    for (idx = 0, j = 0; idx < strlen(plaintext); idx++)
    {
        if ( CHAR_OUT_OF_RANGE(plaintext[idx]) )
        {
            ciphertext[idx] = plaintext[idx];
        }
        else
        {
            ciphertext[idx] = plaintext[idx];
            ciphertext[idx] += key[j] - MIN_ASCII_VALUE;
            ciphertext[idx] = ((ciphertext[idx] - MIN_ASCII_VALUE) % 26) + MIN_ASCII_VALUE;
        }
        j = (j + 1) % strlen(key);
    }

    ciphertext[idx] = 0;
}
