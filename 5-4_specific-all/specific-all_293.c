#include <stdio.h>
#include <string.h>

int main() {
    #define green 2
    #define red 3

    char bands, color1[10], color2[10];
    int mult = 0;

    printf("Select how many bands the resistor has:\n");
    printf("A. 4 bands\n");
    printf("B. 5 bands\n");
    printf("C. 6 bands\n");
    scanf(" %c", &bands);

    switch (bands) {
        case 'a':
        case 'A':
            printf("Enter the colors (e.g., green red): ");
            scanf("%s %s", color1, color2);

            if (strcmp(color1, "green") == 0 && strcmp(color2, "red") == 0) {
                mult = green * red;
                printf("Output: %d\n", mult);
            } else {
                printf("Invalid color combination.\n");
            }
            break;

        default:
            printf("Invalid selection.\n");
            break;
    }

    return 0;
}
