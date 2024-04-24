#include <stdio.h>
#include <stdlib.h>

char* readAddress() {
    char* address = NULL;
    char* temp = NULL;
    char* newAddress = NULL;
    int index = 0;
    int length = 0;
    int c;

    do {
        c = getchar();
        if (c == '\n' || c == EOF) {
            break; // Stop reading on newline or EOF
        }
        
        if (index == length) {
            length += 10; // Increase buffer size by 10 characters
            newAddress = realloc(address, length);
            if (newAddress == NULL) {
                free(address);
                return NULL; // Error handling for realloc failure
            }
            address = newAddress;
        }

        address[index] = (char)c;
        index++;
    } while (1);

    if (address) {
        address[index] = '\0'; // Null-terminate the string
    }

    return address;
}

int main() {
    printf("Enter the employee's address (press Enter twice to finish):\n");
    char* employeeAddress = readAddress();
    
    printf("Employee's address: %s\n", employeeAddress);

    free(employeeAddress); // Don't forget to free dynamically allocated memory

    return 0;
}
