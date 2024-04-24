#include <stdio.h>

int main()
{
    int green = 2, red = 3;
    char bands, color1, color2;
    int mult;

    printf("Select how many bands the resistor has\n");
    printf("A. 4 bands\n");
    printf("B. 5 bands\n");
    printf("C. 6 bands\n");
    scanf(" %c", &bands);

    switch (bands)
    {
        case 'A':
        case 'a':
            printf("Enter the colors: ");
            scanf(" %c %c", &color1, &color2);
            if (color1 == 'green' && color2 == 'red') {
                mult = green * red;
                printf("Value for green is 2 and red is 3. Multiplication result: %d\n", mult);
            } else {
                printf("Invalid colors entered.\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
