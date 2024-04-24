#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int menu_selection, error_flag;
    float force, area, pressure;

    printf("Please select a formula. [0 - 3]\n>>");
    scanf("%d", &menu_selection);
    
    if (menu_selection == 1)
    {
        error_flag = 0;
        system("cls");

        printf("Pressure's formula\n\n");
        
        do {
            error_flag = 0;
            
            printf("Please key in the force applied. (N)\n>>");
            if (scanf("%f", &force) != 1) {
                // Clear the input buffer to prevent an infinite loop
                while (getchar() != '\n');
                
                error_flag = 1;
                printf("Invalid input, please key in a positive number.\n");
            } else if (force <= 0) {
                error_flag = 1;
                printf("Invalid input, please key in a positive number.\n");
            } else {
                printf("Please key in the surface area. (m^2)\n>>");
                if (scanf("%f", &area) != 1) {
                    // Clear the input buffer to prevent an infinite loop
                    while (getchar() != '\n');
                    
                    error_flag = 1;
                    printf("Invalid input, please key in a positive number.\n");
                } else if (area <= 0) {
                    error_flag = 1;
                    printf("Invalid input, please key in a positive number.\n");
                } else {
                    pressure = force / area;
                    printf("The pressure is %.2f Pa.\n\n", pressure);
                }
            }
        } while (error_flag == 1);
    }

    return 0;
}
