    #include <stdio.h> /* only needed for the printf() in main(). */
    #include <string.h>
    /* Create a string of binary digits based on the input value.
       Make sure buffer is big enough to hold result, including
       closing 0-byte.
       Returns address of string.
    */
    static char *binrep (unsigned int val, char *buff, int sz) {
        /* Special case for zero to ensure some output. */
        if (val == 0) {
            strcpy (buff, "0");
            return buff;
        }
        /* Work from the end of the buffer back. */
        buff += sz;
        *buff-- = '\0';
        /* For each bit (going backwards) store character. */
        while (val != 0) {
            *buff-- = ((val & 1) == 1) ? '1' : '0';
            /* Get next bit. */
            val >>= 1;
        }
        return buff+1;
    }