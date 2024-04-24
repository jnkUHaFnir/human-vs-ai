#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int menu_selection, error_flag;
    float force, area, pressure;

    printf("Please select a formula. [0 - 3]\n>>");
    if(scanf("%d", &menu_selection) != 1)
    {
        printf("Invalid input. Please enter a number.\n");
        return 1;
    }

    if(menu_selection == 1)
    {
        error_flag = 0;
        system("cls"); 

        printf("Pressure's formula\n\n");
        
        do
        {
            error_flag = 0;
            printf("Please enter the force applied.(N)\n>>");
            if(scanf("%f", &force) != 1)
            {
                printf("Invalid input. Please enter a number.\n");
                return 1;
            }

            if(force > 0)
            {
                printf("Please enter the surface area.(m^2)\n>>");
                if(scanf("%f", &area) != 1)
                {
                    printf("Invalid input. Please enter a number.\n");
                    return 1;
                }
                
                pressure = force / area;
                
                printf("The pressure is %.2f Pa.\n\n", pressure);
            }
            else
            {
                error_flag = 1;
                printf("Invalid input, please enter a positive number.\n");
            }
        } while (error_flag == 1);
    }

    return 0;
}
