#include <stdio.h>
#include <limits.h>

int main() {
    long userInput;
    int intValue;

    printf("Enter a number: ");
    if (scanf("%ld", &userInput) != 1) {
        printf("Invalid input, please try again\n");
        return 1;
    }

    if (userInput > INT_MAX || userInput < INT_MIN) {
        printf("Input value is too large or too small for an int, please try again\n");
    } else {
        intValue = (int)userInput;
        printf("Input value is valid and can be stored as an int: %d\n", intValue);
    }

    return 0;
}
