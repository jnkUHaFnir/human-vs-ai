#include <stdio.h>

enum Colors {black, brown, red, orange, yellow, green, blue, violet, gray, white};

int main() {

    enum Colors color1, color2;
    int mult;

    printf("Enter the colors (0-9 corresponding to colors black to white)\n");
    printf("Color 1: ");
    scanf("%d", &color1);
    printf("Color 2: ");
    scanf("%d", &color2);
    
    if (color1 == green && color2 == red) {
        mult = 6;
    } else {
        mult = color1 * 10 + color2; // Assuming a simple multiplication based on position, e.g., value for red = 2, green = 5
    }

    printf("Result: %d\n", mult);

    return 0;
}
