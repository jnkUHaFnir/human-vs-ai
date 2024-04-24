#include <stdio.h>

// Define color values using #define preprocessor directive correctly
#define GREEN 2
#define RED 3

int main()
{
    char bands; // to hold the selected option for the number of bands
    char color1[10], color2[10]; // these should be arrays of char to hold strings (color names)
    int mult; // to hold the multiplication result
    int value1 = 0, value2 = 0; // temp variables to hold numeric values for colors

    printf("Select how many bands the resistor has:\n");
    printf("A. 4 bands\n");
    printf("B. 5 bands\n");
    printf("C. 6 bands\n");
    scanf(" %c", &bands); // added space before %c to eat any whitespace

    switch (bands)
    {
    case 'a':
    case 'A':
        printf("Enter the two colors: ");
        scanf("%s %s", color1, color2); // reading strings into char arrays

        // Assign corresponding values to color names
        if (strcmp(color1, "green") == 0) {
            value1 = GREEN;
        }
        if (strcmp(color2, "red") == 0) {
            value2 = RED;
        }

        mult = value1 * value2;
        printf("Resulting value: %d\n", mult);
        break;
    // Add cases for 'B' and 'C' if needed
    }

    getchar(); // to catch the newline character
    getchar(); // to wait for user input before closing
    return 0;
}
