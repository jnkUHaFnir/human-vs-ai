#include <stdio.h>
#include <string.h> // For using strlen()

int main() {
    char address[1000];

    printf("Enter your address: ");
    fgets(address, sizeof(address), stdin);

    // Removes the newline character if it's at the end of the string
    size_t len = strlen(address);
    if (len > 0 && address[len - 1] == '\n') {
        address[len - 1] = '\0';
    }

    printf("Your address is: %s\n", address);

    return 0;
}
