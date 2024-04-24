#include <stdio.h>
#include <stdlib.h>

char* readAddress() {
    char* address = NULL;
    char* temp = NULL;
    size_t len = 0;
    size_t totalLen = 0;
    ssize_t bytesRead;

    do {
        temp = (char*)realloc(address, totalLen + 100); // read in chunks of 100 characters
        if (temp == NULL) {
            free(address);
            return NULL; // Error in memory allocation
        }
        address = temp;

        bytesRead = getline(&address[totalLen], &len, stdin);

        if (bytesRead > 0) {
            totalLen += bytesRead;
        } else {
            break; // End of input
        }
    } while (!feof(stdin));

    return address;
}

int main() {
    char* employeeAddress = readAddress();
    if (employeeAddress != NULL) {
        printf("Address: %s\n", employeeAddress);
        free(employeeAddress);
    }

    return 0;
}
