#include <stdio.h>
#include <string.h>

int main() {
    char color1[10], color2[10];
    int mult;
    
    printf("Enter the colors (e.g. green red): ");
    scanf("%s %s", color1, color2);
    
    if (strcmp(color1, "green") == 0 && strcmp(color2, "red") == 0) {
        mult = 6;
        printf("Output: %d\n", mult);
    } else {
        printf("Invalid colors\n");
    }
    
    return 0;
}
