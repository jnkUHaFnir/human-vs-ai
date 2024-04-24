#include <stdio.h>

int main() {
    // Define values for colors
    #define GREEN 2
    #define RED 3

    char bands, color1, color2;
    int mult;

    printf("Select how many bands the resistor has\n");
    printf("A. 4 bands\n");
    printf("B. 5 bands\n");
    printf("C. 6 bands\n");
    scanf(" %c", &bands); // Added space before %c to consume any leading whitespace

    switch (bands) {
        case 'a':
        case 'A':
            printf("Enter the colors (e.g., green red): ");
            scanf(" %c %c", &color1, &color2);

            // Assign values based on colors
            if (color1 == 'green' && color2 == 'red') {
                mult = GREEN * RED;
                printf("Color combination is green and red, resulting value: %d\n", mult);
            } else {
                printf("Invalid color combination\n");
            }
            break;

        default:
            printf("Invalid bands selection\n");
            break;
    }

    return 0;
}
