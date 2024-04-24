#include <stdio.h>

int main() {
    char buffer[100]; // Assuming a maximum line length of 99 characters
    
    printf("Enter a line of text: ");
    fgets(buffer, sizeof(buffer), stdin);
    
    printf("You entered: %s", buffer);
    
    return 0;
}
