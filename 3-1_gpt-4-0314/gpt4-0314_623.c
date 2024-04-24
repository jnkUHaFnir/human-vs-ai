#include <stdio.h>

int main() {
    char address[1000];

    printf("Enter your address: ");
    fgets(address, sizeof(address), stdin);
    address[strcspn(address, "\n")] = 0;  // Remove the newline character at the end.

    printf("Your address is: %s\n", address);

    return 0;
}
