#include <stdio.h>
#include <stdlib.h>

char* readAddress() {
    char* address = NULL;
    size_t len = 0;
    ssize_t read;

    printf("Enter the address (press Ctrl+D on a new line to finish):\n");

    while ((read = getline(&address, &len, stdin)) != -1) {
        if (address[read - 1] == '\n') {
            address[read - 1] = '\0';  // Remove newline character
            break;
        }
    }

    return address;
}

int main() {
    char* employeeAddress = readAddress();
    printf("Employee Address: %s\n", employeeAddress);

    free(employeeAddress); // Don't forget to free the allocated memory

    return 0;
}
