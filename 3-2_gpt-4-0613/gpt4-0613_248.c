#include <stdio.h>
#include <stdlib.h>

void clear_input_buffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int main(void) {
    int menu_selection, error_flag;
    float force, area, pressure;
    
    printf("Please select a formula. [0 - 3]\n>>");
    scanf("%d", &menu_selection);
    clear_input_buffer();
    if (menu_selection == 1) {
        error_flag = 0;
        printf("Pressure's formula\n\n");
        do {
            error_flag = 0;
            printf("Please key in the force applied.(N)\n>>");
            if(scanf("%f", &force) != 1) {
                printf("Invalid input, please key in a positive number.\n");
                clear_input_buffer();
                continue;
            }
            if (force > 0) {
                printf("Please key in the surface area.(m^2)\n>>");
                if (scanf("%f", &area) != 1) {
                    printf("Invalid input, please key in a positive number.\n");
                    clear_input_buffer();
                    continue;
                }
                pressure = force / area;
                printf("The pressure is %.2fPa.\n\n", pressure);
            } else {
                error_flag = 1;
                printf("Invalid input, please key in a positive number.\n");
            }
        } while (error_flag == 1);
    }
    return 0;
}
