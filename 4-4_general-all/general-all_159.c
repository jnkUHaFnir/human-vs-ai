#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    char input[20]; // Assuming a maximum input length of 20 characters
    char *endptr;
    long int inputLong;

    printf("Enter an integer: ");
    fgets(input, sizeof(input), stdin);

    // Convert the input to a long value
    inputLong = strtol(input, &endptr, 10);

    // Check if conversion was successful and within the int range
    if ((inputLong > INT_MAX || inputLong < INT_MIN) || (*endptr != '\n' && *endptr != '\0')) {
        printf("Input value is out of int range or not a valid integer. Please re-enter.\n");
    } else {
        int inputInt = (int)inputLong; // Now safe to cast to int without truncation
        printf("Input value within int range: %d\n", inputInt);
    }

    return 0;
}
