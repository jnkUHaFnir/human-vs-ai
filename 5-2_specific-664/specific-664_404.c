#include <stdio.h>

int main() {
    char address[1000];

    printf("Enter your address: ");
    scanf(" %[^\n]", address); // Note the space before %[^\n]

    printf("Your address is: %s\n", address);

    return 0;
}
