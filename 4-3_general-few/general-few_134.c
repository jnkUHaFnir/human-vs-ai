#include <stdio.h>

int validate(int low, int high);

int main() {
    // other declarations
    
    // Main Menu display and selection validation
    int selection;
    printf("Selection: ");
    selection = validate(1, 3);

    // Character Creation and attribute calculations
    // other code
    
    return 0;
}

int validate(int low, int high) {
    int s;

    do {
        printf("Enter a number between %d and %d: ", low, high);
        scanf("%d", &s);
        if (s < low || s > high) {
            printf("Invalid input, please try again.\n");
        }
    } while (s < low || s > high);

    return s;
}
