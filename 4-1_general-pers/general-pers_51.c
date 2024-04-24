#include <stdio.h>
#include <stdlib.h>

char* readAddress() {
    char* address = NULL;
    char* temp = NULL;
    size_t len = 0;
    size_t totalLen = 0;

    do {
        temp = realloc(address, totalLen + 1024); // reallocating memory in chunks of 1024 bytes
        if (temp == NULL) {
            // Handle memory allocation failure
            free(address);
            return NULL;
        }
        address = temp;
        
        if (fgets(address + totalLen, 1024, stdin) == NULL) {
            break; // Stop reading on EOF or error
        }

        len = strlen(address + totalLen);
        totalLen += len;
    } while (len > 0 && address[totalLen - 1] != '\n'); // Continue reading until a newline character is encountered or EOF

    // Remove newline character if present
    if (totalLen > 0 && address[totalLen - 1] == '\n') {
        address[totalLen - 1] = '\0';
        totalLen--;
    }

    // Resize to actual length
    temp = realloc(address, totalLen + 1);
    if (temp == NULL) {
        // Handle memory allocation failure
        free(address);
        return NULL;
    }
    address = temp;

    return address;
}

int main() {
    char* employeeAddress = readAddress();
    if (employeeAddress != NULL) {
        printf("Employee Address: %s\n", employeeAddress);
        free(employeeAddress);
    } else {
        printf("Error reading employee address.\n");
    }

    return 0;
}
