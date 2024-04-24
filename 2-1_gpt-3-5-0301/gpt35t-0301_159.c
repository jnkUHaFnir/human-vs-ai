#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int main() {
    char input[20];
    long int num;
    char *endptr;

    printf("Enter a number: ");
    fgets(input, 20, stdin); // read input as a string
    num = strtol(input, &endptr, 10); // convert string to long int
    if (errno == ERANGE || num < INT_MIN || num > INT_MAX || *endptr != '\n') {
        // check for conversion error or overflow, or if the input contains non-numeric characters
        printf("Invalid input. Please enter a number within the range of an int.\n");
    } else {
        printf("The input is valid.\n");
    }
    return 0;
}
