#include <stdio.h>

int main()
{

    #define green 2
    #define red 3

    char bands, color1, color2;
    int mult;

    printf("Select how many bands the resistor has");
    printf("\n A. 4 bands");
    printf("\n B. 5 bands");
    printf("\n C. 6 bands");
    scanf(" %c", &bands);

    switch (bands)
    {
        case 'a':
        case 'A':
            printf("Enter the colors");
            scanf(" %c %c", &color1, &color2);
            if ((color1 == 'green' && color2 == 'red') || (color1 == 'red' && color2 == 'green')) {
                mult = 6;
            } else {
                mult = 0; // Default value for undefined color combination
            }
            printf("%d", mult);
            break;
        default:
            printf("Invalid option");
    }

    getchar();
    return 0;
}
