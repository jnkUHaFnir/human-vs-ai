#include <stdio.h>

int main() {
    char input[100]; // Assuming the input line won't exceed 100 characters

    printf("Enter a line of text: ");
    fgets(input, sizeof(input), stdin);

    printf("You entered: %s", input);

    return 0;
}
