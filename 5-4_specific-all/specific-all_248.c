#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int menu_selection, error_flag;
    float force, area, pressure;

    printf("Please select a formula. [0 - 3]\n>>");
    scanf("%d", &menu_selection);

    if (menu_selection == 1) {
        system("cls");

        printf("Pressure's formula\n\n");

        do {
            error_flag = 0;

            printf("Please key in the force applied. (N)\n>>");
            if (scanf("%f", &force) != 1) {
                printf("Invalid input. Please enter a number.\n");
                while (getchar() != '\n'); // Clear the input buffer
                continue;
            }

            if (force >= 0) {
                printf("Please key in the surface area. (m^2)\n>>");
                if (scanf("%f", &area) != 1) {
                    printf("Invalid input. Please enter a number.\n");
                    while (getchar() != '\n'); // Clear the input buffer
                    continue;
                }

                if (area >= 0) {
                    pressure = force / area;
                    printf("The pressure is %.2f Pa.\n\n", pressure);
                } else {
                    error_flag = 1;
                    printf("Invalid input. Please key in a positive number.\n");
                }
            } else {
                error_flag = 1;
                printf("Invalid input. Please key in a positive number.\n");
            }

        } while (error_flag == 1);
    }

    return 0;
}
