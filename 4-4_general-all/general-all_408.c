#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char* sanitizeString(unsigned char *pCharArg1)
{
    unsigned char *pCharWorker = pCharArg1;

    /* The look-up map */
    unsigned char* charLookup[][2] = { {"ab", "a"}, {"à", "a"}, {"ss", "s"}, {"å", "a"}, {"Å", "A"}, {"ÿ", "y"}, {"XX", ""} };

    while (*pCharWorker != '\0') {
        for (int j = 0; j < sizeof(charLookup) / sizeof(charLookup[0]); j++) {
            if (strcmp(pCharWorker, charLookup[j][0]) == 0) {
                pCharWorker[0] = charLookup[j][1][0];
                pCharWorker[1] = '\0'; // Null terminate the string after replacement
                break;
            }
        }
        pCharWorker++;
    }
    return pCharArg1;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    unsigned char* z = (unsigned char *)argv[1];
    printf("PRINT : %s \n", z);
    unsigned char* p2 = sanitizeString(z);
    printf("Sanitized string: %s \n", p2);
    return 0;
}
