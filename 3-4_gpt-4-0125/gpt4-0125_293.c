#include <stdio.h>
#include <string.h>

// Function to map color names to numerical values
int getColorValue(char* color) {
    if (strcmp(color, "green") == 0) {
        return 2;
    } else if (strcmp(color, "red") == 0) {
        return 3;
    }
    // Optionally, handle unexpected color
    return 0;
}

int main() {
    char bands; 
    char color1[10], color2[10];
    int mult, value1, value2;

    printf("Select how many bands the resistor has\n");
    printf("A. 4 bands\n");
    printf("B. 5 bands\n");
    printf("C. 6 bands\n");
    scanf(" %c", &bands); // Notice the space before %c to consume any newline left in the input buffer

    if (bands == 'a' || bands == 'A') {
        printf("Enter the colors (example: green red): ");
        scanf("%s %s", color1, color2);  // color1 and color2 store the names of the colors
        value1 = getColorValue(color1);
        value2 = getColorValue(color2);
        mult = value1 + value2; // Assuming you want to add values, not multiply; as per your output example
        printf("%d\n", mult);
    } else {
        printf("This example only handles case A for simplicity.\n");
    }

    return 0;
}
