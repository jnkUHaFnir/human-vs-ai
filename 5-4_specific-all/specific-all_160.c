#include <stdio.h>
#include <ctype.h>

int main() {
    char repeat;
    char buffer[100]; // buffer to store the user input

    do {
        printf("Do you want to try again? (Y/N): ");
        fgets(buffer, sizeof(buffer), stdin); // Read the input as a string
        repeat = buffer[0]; // Get the first character from the input

        if (buffer[1] != '\n' || (repeat != 'Y' && repeat != 'N')) {
            printf("Invalid input. Please enter a single character 'Y' or 'N'.\n\n");
            // Clear the input buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

    } while (buffer[1] != '\n' || (repeat != 'N' && repeat != 'Y'));

    return 0;
}
