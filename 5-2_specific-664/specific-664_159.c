#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main() {
    char input[20];  // Assuming the input can be at most 20 characters long

    printf("Enter an integer: ");
    scanf("%s", input);

    // Check the length of the input string
    if(strlen(input) > 10 || (strlen(input) == 10 && strcmp(input, "2147483647") > 0)) {
        printf("Input value is too large for an int. Please re-enter.\n");
    } else {
        int num = atoi(input);  // Convert input to an integer
        if(num > INT_MAX) {
            printf("Input value is too large for an int. Please re-enter.\n");
        } else {
            printf("Input value can be stored in an int.\n");
        }
    }

    return 0;
}
