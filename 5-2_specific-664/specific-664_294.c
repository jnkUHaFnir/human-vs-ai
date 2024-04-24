#include <stdio.h>

int main()
{
    enum Color {green = 2, red = 3};
    
    char bands, color1, color2;
    int mult;
    
    printf("Select how many bands the resistor has\n");
    printf("A. 4 bands\nB. 5 bands\nC. 6 bands\n");
    scanf(" %c", &bands); // Note the space before %c to consume leading whitespace

    switch (bands)
    {
        case 'A':
        case 'a':
            printf("Enter the colors: ");
            scanf(" %c %c", &color1, &color2);
            mult = (color1 == 'g' ? green : red) * (color2 == 'g' ? green : red);
            printf("Resistance value: %d\n", mult);
            break;

        default:
            printf("Invalid selection\n");
            break;
    }

    return 0;
}
