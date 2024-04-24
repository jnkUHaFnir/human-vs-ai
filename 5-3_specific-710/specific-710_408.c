#include <stdio.h>
#include <string.h>

unsigned char* sanitizeString(unsigned char *pCharArg1)
{
    unsigned char *pCharWorker = pCharArg1;

    /* The look-up map for extended ASCII characters
     */
    unsigned char charLookup[][3] = { "ab", "àa", "ss", "åa", "ÅA", "ÿy", "XX", "" };

    while (*pCharWorker != '\0') {
        int j = 0;
        int foundFlag = 0;

        // Loop through the lookup map
        while (*charLookup[j] != '\0') {
            if (*pCharWorker == charLookup[j][0]) {
                foundFlag = 1;
                // Replace the character with the corresponding extended ASCII character
                *pCharWorker = charLookup[j][1];
                break;
            }
            j++;
        }

        if (!foundFlag) {
            // Handle the case where character not found in the lookup map
            // You can choose to ignore, skip, or replace those characters too
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
