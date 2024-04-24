#include <stdio.h>

int main() {
    char buffer[256]; // Assuming maximum line length is 255 characters

    printf("Enter a line of text: ");
    fgets(buffer, sizeof(buffer), stdin);

    printf("You entered: %s\n", buffer);

    return 0;
}
