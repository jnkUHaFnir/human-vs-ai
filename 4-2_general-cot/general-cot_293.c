#include <stdio.h>

#define GREEN 2
#define RED 3

int main()
{
    char bands, color1, color2;
    int mult = 0;

    printf("Select how many bands the resistor has\n");
    printf("A. 4 bands\nB. 5 bands\nC. 6 bands\n");
    scanf(" %c", &bands);

    switch (bands)
    {
        case 'a':
        case 'A':
            printf("Enter the colors (green red): ");
            scanf(" %c %c", &color1, &color2);

            if (color1 == 'g' && color2 == 'r'){
                mult = GREEN * RED;
                printf("Value: %d\n", mult);
            }
            else {
                printf("Invalid colors entered.\n");
            }
            break;

        // Add cases for other band options if needed

        default:
            printf("Invalid option selected.\n");
    }

    return 0;
}
