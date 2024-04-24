    #include <stdio.h>
    #include <string.h>
    static char *binrep (unsigned int x, char *buff, int sz) {
        if (x == 0) {
            strcpy (buff, "0");
            return buff;
        }
        buff += sz;
        *buff-- = '\0';
        while (x != 0) {
            *buff-- = ((x & 1) == 1) ? '1' : '0';
            x >>= 1;
        }
        return buff+1;
    }
    #define SZ 32
    int main(int argc, char *argv[]) {
        int i;
        int n;
        char buff[SZ+1];
        for (i = 1; i < argc; i++) {
            n = atoi (argv[i]);
            printf("[%3d] %9d -> %s (from '%s')\n", i, n, binrep(n,buff,SZ), argv[i]);
        }
        return 0;
    }