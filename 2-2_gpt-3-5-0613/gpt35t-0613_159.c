#include <stdio.h>
#include <limits.h>

int main() {
    int input;
    
    printf("Enter a number: ");
    if (scanf("%d", &input) != 1) {
        printf("Invalid input! Please enter an integer.\n");
        return 0;
    }

    if (input > INT_MAX || input < INT_MIN) {
        printf("Input outside the valid range! Please re-enter the data.\n");
    } else {
        printf("Valid input! The number is: %d\n", input);
    }

    return 0;
}
