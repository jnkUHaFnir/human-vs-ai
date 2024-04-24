#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int menu_selection;
    float force, area, pressure;
    char buffer[100]; // buffer for clearing input buffer

    printf("Please select a formula. [1 - 3]\n>>");
    scanf("%d", &menu_selection);

    if (menu_selection == 1)
    {
        printf("Pressure's formula\n\n");
        do
        {
            printf("Please key in the force applied. (N)\n>>");
            if (scanf("%f", &force) != 1)
            {
                printf("Invalid input, please key in a number.\n");
                scanf("%s", buffer); // clear the input buffer
                continue;
            }

            if (force <= 0)
            {
                printf("Invalid input, please key in a positive number.\n");
                continue;
            }

            printf("Please key in the surface area. (m^2)\n>>");
            if (scanf("%f", &area) != 1)
            {
                printf("Invalid input, please key in a number.\n");
                scanf("%s", buffer); // clear the input buffer
                continue;
            }

            if (area <= 0)
            {
                printf("Invalid input, please key in a positive number.\n");
                continue;
            }

            pressure = force / area;

            printf("The pressure is %.2f Pa.\n\n", pressure);
        } while (1);
    }

    return 0;
}
