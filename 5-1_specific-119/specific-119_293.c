#include <stdio.h>

int main()
{
    int green = 2, red = 3;
    char bands, color1, color2;
    int mult = 0;

    printf("Select how many bands the resistor has\n");
    printf("A. 4 bands\nB. 5 bands\nC. 6 bands\n");
    scanf(" %c", &bands);

    switch (bands)
    {
        case 'A':
        case 'a':
            printf("Enter the colors (e.g., green red): ");
            scanf(" %c %c", &color1, &color2);

            if (color1 == 'g' && color2 == 'r') {
                mult = green * red;
                printf("Result: %d\n", mult);
            } else {
                printf("Invalid colors entered.\n");
            }
            break;
        
        // Add cases for other band options as needed

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
