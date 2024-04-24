#include <stdio.h>

int main()
{
    #define green 2
    #define red 3

    char bands, color1, color2;
    int mult;

    printf("Select how many bands the resistor has:\n");
    printf("A. 4 bands\n");
    printf("B. 5 bands\n");
    printf("C. 6 bands\n");
    scanf("%c", &bands);

    switch (bands)
    {
        case 'a':
        case 'A':
            printf("Enter the colors (green and red):\n");
            scanf("%d %d", &color1, &color2);
            mult = green * red;
            printf("Result: %d\n", mult);
            break;
        default:
            printf("Invalid selection\n");
    }

    return 0;
}
