#include <stdio.h>
#include <string.h>

int main()
{
    #define GREEN 2
    #define RED 3

    char bands, color1[10], color2[10];
    int mult = 0;

    printf("Select how many bands the resistor has:\n");
    printf("A. 4 bands\nB. 5 bands\nC. 6 bands\n");
    scanf(" %c", &bands);

    if (bands == 'A' || bands == 'a')
    {
        printf("Enter the colors (e.g., green red): ");
        scanf("%s %s", color1, color2);

        if (strcmp(color1, "green") == 0 && strcmp(color2, "red") == 0)
        {
            mult = GREEN * RED;
            printf("Output: %d\n", mult);
        }
        else
        {
            printf("Invalid colors entered.\n");
        }
    }
    else
    {
        printf("Invalid choice for the number of bands.\n");
    }

    return 0;
}
