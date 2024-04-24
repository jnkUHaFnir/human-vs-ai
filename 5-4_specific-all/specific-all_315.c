#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertToBase10(unsigned char* n, size_t size) {
    char *result = (char*)malloc(size * 3); // Maximum 3 characters per digit
    
    char *tmp = (char*)malloc(3); // Temporary storage for each digit
    memset(result, 0, size * 3);
    memset(tmp, 0, 3);

    for(size_t i = size; i > 0; i--) {
        unsigned short carry = 0;
        for(size_t j = 0; j < strlen(result); j++) {
            unsigned short x = (result[j] - '0') * 256 + carry;
            result[j] = (x % 10) + '0';
            carry = x / 10;
        }
        
        while(carry) {
            tmp[0] = (carry % 10) + '0';
            strcat(tmp, result);
            strncpy(result, tmp, strlen(tmp));
            carry /= 10;
        }
    }

    printf("Number in base 10: %s\n", result);
    
    free(tmp);
    free(result);
}

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;
    
    convertToBase10(n, 3);

    return 0;
}
