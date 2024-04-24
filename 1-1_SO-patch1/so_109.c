    #include <stdio.h> /* only needed for the printf() in main(). */
    #include <string.h>
    static char *binrep (unsigned int x, char *buff, int sz) {
        /* Special case for zero to ensure some output. */
        if (x == 0) {
            strcpy (buff, "0");
            return buff;
        }
        /* Work from the end of the buffer back. */
        buff += sz;
        *buff-- = '\0';
        /* For each bit (going backwards) store character. */
        while (x != 0) {
            *buff-- = ((x & 1) == 1) ? '1' : '0';
            /* Get next bit. */
            x >>= 1;
        }
        return buff+1;
    }