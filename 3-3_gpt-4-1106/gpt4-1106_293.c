#include <stdio.h>

// Define color values using an enumeration
typedef enum {
    COLOR_UNDEFINED = 0, // For undefined colors
    GREEN = 2,
    RED = 3,
    // ... (Add other colors if needed)
} Color;

// Function that translates color names to their corresponding enumeration values
Color getColorValue(const char* colorName) {
    if(strcmp(colorName, "green") == 0) return GREEN;
    if(strcmp(colorName, "red") == 0) return RED;
    // ... (Handle other color names if needed)
    return COLOR_UNDEFINED;
}

int main() {
    char bands;
    char color1[20], color2[20]; // Use arrays to store string inputs
    int mult;
    
    printf("Select how many bands the resistor has:\n");
    printf("A. 4 bands\n");
    printf("B. 5 bands\n");
    printf("C. 6 bands\n");
    scanf(" %c", &bands); // Notice the leading space in the format string to consume any leftover whitespace
    
    // The switch must enclose its cases in braces
    switch (bands) {
        case 'a':
        case 'A':
            printf("Enter the two colors (e.g., green red):\n");
            scanf("%19s %19s", color1, color2); // Always limit string input to avoid buffer overflow
            
            // Convert color names to their numeric values
            Color value1 = getColorValue(color1);
            Color value2 = getColorValue(color2);

            // Make sure both color values are defined
            if(value1 == COLOR_UNDEFINED || value2 == COLOR_UNDEFINED) {
                printf("Invalid color name entered.\n");
            } else {
                mult = value1 * value2;
                printf("The result is: %d\n", mult);
            }
            break;
        // ... (Handle other cases B and C if needed)
    }
    
    return 0;
}
