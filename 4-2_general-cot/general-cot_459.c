#include <stdio.h>

#define BUFFER_SIZE 100

int main() {
    char buffer[BUFFER_SIZE];
    
    printf("Enter a string: ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        // Input successfully read
        printf("You entered: %s", buffer);
    } else {
        // Handle error
        fprintf(stderr, "Error reading input\n");
    }
    
    return 0;
}
