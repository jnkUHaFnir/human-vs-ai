#include <stdio.h>

int main() {
    char line[100]; // Assuming the maximum length of the input line is 100 characters

    printf("Enter a line of text: ");
    fgets(line, sizeof(line), stdin);

    printf("You entered: %s", line);

    return 0;
}
