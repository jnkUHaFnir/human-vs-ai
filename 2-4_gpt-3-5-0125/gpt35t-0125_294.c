#include <stdio.h>

#define GREEN 2
#define RED 3

int main()
{

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

            int val1, val2;
            switch (color1)
            {
                case 'g':
                case 'G':
                    val1 = GREEN;
                    break;
                case 'r':
                case 'R':
                    val1 = RED;
                    break;
                default:
                    val1 = 0;
            }

            switch (color2)
            {
                case 'g':
                case 'G':
                    val2 = GREEN;
                    break;
                case 'r':
                case 'R':
                    val2 = RED;
                    break;
                default:
                    val2 = 0;
            }

            mult = val1 * val2;
            
            printf("The output is: %d\n", mult);
            break;

        default:
            printf("Invalid input. Please try again.\n");
    }

    getchar();
    return 0;
}
