#include <stdio.h>
#include <string.h>

int main() {
    char address[1000];

    printf("Enter your address: ");
    fgets(address, sizeof(address), stdin);

    // Remove the trailing newline character
    address[strcspn(address, "\n")] = '\0';

    printf("Your address is: %s\n", address);

    return 0;
}
