#include <stdio.h>

int main() {
    char address[1000];

    printf("Enter your address: ");
    scanf(" %[^\n]", address);

    printf("Your address is: %s\n", address);

    return 0;
}
``` 

With this change, your program should now read the entire line including spaces when the user inputs their address.
