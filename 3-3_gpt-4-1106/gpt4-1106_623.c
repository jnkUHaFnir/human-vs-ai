#include <stdio.h>

int main(void) {
    char address[1000];

    printf("Enter your address: ");
    // Use fgets() instead of scanf() to read the entire line
    // Note that &address is not needed, as address is an array (which decays to a pointer)
    fgets(address, sizeof(address), stdin);

    // Remove the newline character at the end of the input, if there is one
    // This occurs because fgets() includes the newline character in the buffer
    address[strcspn(address, "\n")] = '\0';

    printf("Your address is: %s\n", address);

    return 0;
}
scanf("%999[^\n]", address); // Read up to 999 characters until a newline is encountered
