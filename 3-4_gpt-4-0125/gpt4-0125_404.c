#include <stdio.h>

int main() {
    char address[1000];

    printf("Enter your address: ");
    // Note: Always specify the size of the input buffer to avoid buffer overflow
    fgets(address, sizeof(address), stdin);

    // fgets includes the newline character in the buffer. You might want to remove it.
    address[strcspn(address, "\n")] = 0; // This line removes the newline character if present.

    printf("Your address is: %s\n", address);

    return 0;
}
