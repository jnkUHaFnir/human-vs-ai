#include <stdio.h>

int main() {
    char buffer[100];
    
    printf("Enter your name: ");
    fgets(buffer, sizeof(buffer), stdin);

    printf("Your name is: %s\n", buffer);

    return 0;
}
