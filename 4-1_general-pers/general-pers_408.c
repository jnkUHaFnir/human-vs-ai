#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char* sanitizeString(unsigned char *pCharArg1) {
    unsigned char *pCharWorker = pCharArg1;

    // The look-up map
    unsigned char* charLookup[] = { "ab", "àa", "ss", "åa", "ÅA", "ÿy", "XX", "" };

    // Create a buffer for the sanitized output
    unsigned char* sanitizedString = strdup(pCharArg1); // Allocate memory for the new string

    while (*pCharWorker != '\0') {
        unsigned char* originalChar = pCharWorker;
        int foundReplacement = 0;

        for (int j = 0; charLookup[j][0] != '\0'; j++) {
            if (*pCharWorker == charLookup[j][0]) {
                sanitizedString[originalChar - pCharArg1] = charLookup[j][1];
                foundReplacement = 1;
                break;
            }
        }

        if (!foundReplacement) {
            // Handle non-matching characters here if needed
        }

        pCharWorker++;
    }

    return sanitizedString;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return 1;
    }

    unsigned char* z = argv[1];
    printf("PRINT : %s \n", z);
    unsigned char* p2 = sanitizeString(z);
    printf("Sanitized string: %s \n", p2);

    free(p2); // Free the memory allocated by strdup

    return 0;
}
