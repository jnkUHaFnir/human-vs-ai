#include <stdio.h>

int main() {
    char address[1000];

    printf("Enter your address: ");
    scanf(" %[^\n]", address); // Note the space before the %[^\n] to consume leading whitespace

    printf("Your address is: %s", address);

    return 0;
}
