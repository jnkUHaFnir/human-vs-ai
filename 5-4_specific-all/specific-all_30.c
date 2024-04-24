#include <stdio.h>

int main() {
    char buffer[100]; // Assuming 100 characters max per line, adjust as needed

    printf("Enter a line of text: ");
    fgets(buffer, sizeof(buffer), stdin);

    printf("You entered: %s", buffer);

    return 0;
}
