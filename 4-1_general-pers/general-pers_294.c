#include <stdio.h>
#include <string.h>

// Define the values for the colors
#define GREEN 2
#define RED 3

int main()
{
    char bands, color1[10], color2[10];
    int mult = 0;

    printf("Select how many bands the resistor has\n");
    printf("A. 4 bands\n");
    printf("B. 5 bands\n");
    printf("C. 6 bands\n");
    scanf(" %c", &bands);

    switch (bands)
    {
        case 'a':
        case 'A':
            printf("Enter the colors (e.g., green red): ");
            scanf("%s %s", color1, color2);

            // Compare the colors entered
            if (strcmp(color1, "green") == 0 && strcmp(color2, "red") == 0)
            {
                mult = GREEN * RED;
            }
            else
            {
                printf("Invalid colors entered!\n");
            }
            printf("Result: %d\n", mult);
            break;

        default:
            printf("Invalid choice for bands selected\n");
            break;
    }

    return 0;
}
