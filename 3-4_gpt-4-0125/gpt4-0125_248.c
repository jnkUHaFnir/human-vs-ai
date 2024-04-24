#include <stdio.h>
#include <stdlib.h>

void clear_input_buffer(void) {
    // Read until the end of the current line or end-of-file
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int main(void) {
    int menu_selection;
    float force, area, pressure;

    printf("Please select a formula. [0 - 3]\n>> ");
    scanf("%d", &menu_selection);

    if (menu_selection == 1) {
        system("cls");

        printf("Pressure's formula\n\n");
        while (1) {
            printf("Please key in the force applied. (N)\n>> ");
            if (scanf("%f", &force) != 1) {
                clear_input_buffer();  // Clear the invalid input before retrying
                printf("Invalid input. Please enter a number.\n");
                continue;  // Start the loop over
            }

            if (force > 0) {
                printf("Please key in the surface area. (m^2)\n>> ");
                if (scanf("%f", &area) != 1) {
                    clear_input_buffer();  // Clear the invalid input before continuing
                    printf("Invalid input. Please enter a number.\n");
                    continue;  // Since the loop should only repeat for invalid force, we need to ensure the area is also correctly input. If not, you might want a separate validation for area or a way to return to force input.
                }

                pressure = force / area;

                printf("The pressure is %.2fPa.\n\n", pressure);
                break; // Break the loop if everything is valid
            } else {
                clear_input_buffer();  // Clear the buffer in case of a negative float that was correctly parsed
                printf("Invalid input, please key in a positive number.\n");
                // No need to continue explicitly here, as the condition will go back to the beginning of the loop
            }
        }
    }

    return 0;
}
