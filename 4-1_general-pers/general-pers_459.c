#include <stdio.h>

int main() {
    char buffer[10];
    
    printf("Enter your name: ");
    scanf("%s", buffer);

    printf("Hello, %s!\n", buffer);
    
    return 0;
}
