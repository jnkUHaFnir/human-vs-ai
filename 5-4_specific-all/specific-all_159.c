#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    char input[20]; // assuming input will be less than 20 characters
    char *endptr;
    long num;

    printf("Enter a number: ");
    fgets(input, sizeof(input), stdin);

    // Convert input to a long integer
    num = strtol(input, &endptr, 10);

    // Check for errors in conversion
    if ((num == LONG_MIN || num == LONG_MAX) && errno == ERANGE) {
        printf("Input out of range. Please re-enter a valid number.\n");
    } else if (num > INT_MAX || num < INT_MIN) {
        printf("Input out of range for int. Please re-enter a valid number.\n");
    } else {
        int number = (int)num;
        printf("Integer value entered: %d\n", number);
    }

    return 0;
}
