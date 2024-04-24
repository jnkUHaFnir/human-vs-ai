#include <stdio.h>

int main() {
    char buffer[100]; // Adjust the size as needed

    printf("Enter a string: ");
    fgets(buffer, sizeof(buffer), stdin);

    // Remove newline character if it exists
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len-1] == '\n') {
        buffer[len-1] = '\0';
    }

    printf("You entered: %s\n", buffer);
    
    return 0;
}
