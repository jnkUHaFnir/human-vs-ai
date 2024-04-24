#include <stdio.h>

// Define colors as constants
typedef enum {
    green = 2,
    red = 3
} Color;

int main()
{
    char bands, color1, color2;
    int mult;

    printf("Select how many bands the resistor has");
    printf("\n A. 4 bands");
    printf("\n B. 5 bands");
    printf("\n C. 6 bands\n");
    scanf(" %c", &bands); // Correct format specifier and add space before %c

    switch (bands) {
        case 'a':
        case 'A':
            printf("Enter the colors (e.g., green red): ");
            scanf(" %c %c", &color1, &color2);
          
            // Calculate multiplication of color values
            mult = (Color)color1 * (Color)color2;
            printf("Result: %d\n", mult);
            break;

        default:
            printf("Invalid option\n");
            break;
    }

    getchar();
    return 0;
}
