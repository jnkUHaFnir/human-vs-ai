#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char* sanitizeString(unsigned char *pCharArg1)
{
    unsigned char *pCharWorker = pCharArg1;

    // The look-up map
    unsigned char* charLookup[] = {"ab","àa", "ss", "åa", "ÅA", "ÿy", "XX", "" };

    size_t inputLen = strlen((char*)pCharWorker);

    while (*pCharWorker != '\0') {
        for (int j = 0; charLookup[j][0] != '\0'; j++) {
            size_t lookUpLen = strlen((char*)charLookup[j]);

            if (strncmp((char*)pCharWorker, (char*)charLookup[j], inputLen) == 0) {
                if (inputLen == lookUpLen) {
                    // Exact match found, replace with corresponding value
                    strcpy((char*)pCharWorker, (char*)(charLookup[j] + inputLen));
                }
            }
        }
        pCharWorker++;
    }

    return pCharArg1;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return 1;
    }

    unsigned char* z = (unsigned char*)argv[1];
    printf("PRINT : %s \n", z);
    unsigned char* p2 = sanitizeString(z);
    printf("Sanitized string: %s \n", p2);

    return 0;
}
