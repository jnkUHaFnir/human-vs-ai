#include <stdio.h>
#include <stdlib.h>

int main() {
    int menu_selection;
    float force, area, pressure;

    printf("Please select a formula. [1 - 3]\n>> ");
    while (scanf("%d", &menu_selection) != 1  || (menu_selection < 1 || menu_selection > 3)) {
        printf("Invalid selection. Please select a formula. [1 - 3]\n>> ");
        while (getchar() != '\n'); // Discards incorrect input until the end of the line
    }

    if (menu_selection == 1) {
        system("cls");
        printf("Pressure's formula\n\n");

        while (1) { // Infinite loop until correct input is provided and processed
            printf("Please key in the force applied. (N)\n>> ");
            if (scanf("%f", &force) != 1 || force <= 0) { // Check both the return value of scanf and value of force
                printf("Invalid input, please key in a positive number.\n");
                while (getchar() != '\n'); // Discards non-float input
                continue; // Skip to the next iteration
            }

            printf("Please key in the surface area. (m^2)\n>> ");
            if (scanf("%f", &area) != 1 || area <= 0) { // Check return of scanf and value of area
                printf("Invalid input, please key in a positive number.\n");
                while (getchar() != '\n'); // Discards non-float input
                continue; // Skip to the next iteration
            }

            pressure = force / area;
            printf("The pressure is %.2fPa.\n\n", pressure);
            break; // Exit loop after successful input and calculation
        }
    }
    
    return 0;
}
