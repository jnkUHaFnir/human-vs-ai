    void vigenereEncrypt( const char  plaintext[], char ciphertext[], const char key[] )
    {
      for(int i = 0, j = 0; i < strlen(plaintext); ++i )
      {
        ciphertext[i] = plaintext[i];
        if ( !CHAR_OUT_OF_RANGE(plaintext[i]) )
        {
            ciphertext[i] += key[j] - MIN_ASCII_VALUE;
    
            if (ciphertext[i] > MAX_ASCII_VALUE)
                ciphertext[i] -= MAX_ASCII_VALUE - MIN_ASCII_VALUE + 1;
        }
        j = (j + 1) % strlen(key);
      }
    
      ciphertext[i] = 0;
    }