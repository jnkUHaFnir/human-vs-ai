#include <stdio.h>
#include <string.h>

// Function to return the value of the given color
int get_color_value(char *color) {
    if (strcmp(color, "green") == 0) {
        return 2;
    } else if (strcmp(color, "red") == 0) {
        return 3;
    } else {
        return 0; // Return 0 if the color is not recognized
    }
}

int main() {
    char bands;
    char color1[10], color2[10];
    int mult;

    printf("Select how many bands the resistor has");
    printf("\n A. 4 bands");
    printf("\n B. 5 bands");
    printf("\n C. 6 bands");
    scanf(" %c", &bands);

    switch (bands) {
        case 'a':
        case 'A':
            printf("Enter the colors: ");
            scanf(" %9s %9s", color1, color2);
            mult = get_color_value(color1) * get_color_value(color2);
            printf("%d", mult);
            break;
        default:
            printf("Invalid option.");
            break;
    }

    getchar();
    return 0;
}
