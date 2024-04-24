#include <stdio.h>
#include <string.h> // Include this header for string comparison functions

// Define constants for the colors
#define GREEN 2
#define RED 3

int main() {
    char bands;
    char color1[20], color2[20]; // Use arrays of characters (strings) to store color names.
    int value1 = 0, value2 = 0; // Initialize values for the colors.

    printf("Select how many bands the resistor has");
    printf("\n A. 4 bands");
    printf("\n B. 5 bands");
    printf("\n C. 6 bands\n");
    scanf(" %c", &bands); // Notice the space before %c to skip any newline left in the input buffer.

    switch (bands) {
        case 'a':
        case 'A':
            printf("Enter the colors: ");
            scanf("%19s %19s", color1, color2); // Read strings into the arrays, limiting the input to avoid buffer overflow.

            // Assign values based on the first color
            if (strcmp(color1, "green") == 0) {
                value1 = GREEN;
            } else if (strcmp(color1, "red") == 0) {
                value1 = RED;
            } // Add more colors as else if branches here as needed.

            // Assign values based on the second color
            if (strcmp(color2, "green") == 0) {
                value2 = GREEN;
            } else if (strcmp(color2, "red") == 0) {
                value2 = RED;
            } // Similarly, add more colors here.

            int result = value1 + value2; // Calculate the result as the sum of the two values.
            printf("Output = %d\n", result);
            break;

        // Handle other cases for B and C if necessary.
        default:
            printf("Invalid selection.\n");
    }

    return 0;
}
