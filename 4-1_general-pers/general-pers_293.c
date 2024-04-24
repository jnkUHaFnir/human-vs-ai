#include <stdio.h>
#include <string.h> // Include string.h for using strcmp function

int main() {

    char bands, color1[10], color2[10]; // color1 and color2 should be strings
    int mult = 0;

    printf("Select how many bands the resistor has\n");
    printf("A. 4 bands\n");
    printf("B. 5 bands\n");
    printf("C. 6 bands\n");
    scanf(" %c", &bands); // Added a space before %c to ignore leading whitespace

    switch (bands) {
        case 'a':
        case 'A':
            printf("Enter the colors (green red): ");
            scanf("%s %s", color1, color2);

            if ((strcmp(color1, "green") == 0) && (strcmp(color2, "red") == 0)) {
                mult = 6; // Set the value based on the defined relationship
            } else {
                printf("Invalid colors entered.\n");
            }
            break;
            
        default:
            printf("Invalid selection. Choose A, B, or C.\n");
    }

    if (mult > 0) {
        printf("The value assigned is: %d\n", mult);
    }

    getchar();
    return 0;
}
