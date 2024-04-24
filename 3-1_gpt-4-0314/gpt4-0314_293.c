#include <stdio.h>
#include <string.h>

int get_value_for_color(const char *color);

int main() {
    char bands, color1[20], color2[20];
    int mult;

    printf("Select how many bands the resistor has");
    printf("\n A. 4 bands");
    printf("\n B. 5 bands");
    printf("\n C. 6 bands\n");
    scanf(" %c", &bands);

    switch (bands) {
        case 'a':
        case 'A':
            printf("Enter the colors: ");
            scanf("%s %s", color1, color2);
            mult = get_value_for_color(color1) * get_value_for_color(color2);
            printf("Output = %d\n", mult);
            break;
        default:
            printf("Invalid option\n");
            break;
    }

    getchar();
    return 0;
}

int get_value_for_color(const char *color) {
    if (strcmp(color, "green") == 0) {
        return 2;
    } else if (strcmp(color, "red") == 0) {
        return 3;
    }
    // Add more colors here, but for now return 0 if it's an unrecognized color
    return 0;
}
