#include <stdio.h>

int main() {
    #define green 2
    #define red 3

    char bands, color1, color2;
    int mult;

    printf("Select how many bands the resistor has:\n");
    printf("A. 4 bands\n");
    printf("B. 5 bands\n");
    printf("C. 6 bands\n");
    scanf(" %c", &bands); // space before %c to consume the newline character

    switch (bands) {
        case 'A':
        case 'a':
            printf("Enter the colors (e.g., green red): ");
            scanf(" %c %c", &color1, &color2);

            if (color1 == 'g') {
                color1 = green;
            } else if (color1 == 'r') {
                color1 = red;
            } else {
                printf("Invalid color input\n");
                return 1;
            }

            if (color2 == 'g') {
                color2 = green;
            } else if (color2 == 'r') {
                color2 = red;
            } else {
                printf("Invalid color input\n");
                return 1;
            }

            mult = color1 * color2;
            printf("Result: %d\n", mult);
            break;

        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}
