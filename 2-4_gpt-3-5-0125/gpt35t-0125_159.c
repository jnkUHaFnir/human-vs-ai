#include <stdio.h>
#include <limits.h>

int main() {
    int input;
    char inputStr[100];

    printf("Enter a number: ");
    fgets(inputStr, 100, stdin);

    if (sscanf(inputStr, "%d", &input) != 1) {
        printf("Invalid input. Please enter a number.\n");
    } else if (input > INT_MAX) {
        printf("Number is too large. Please enter a smaller number.\n");
    } else {
        printf("Number stored successfully: %d\n", input);
    }

    return 0;
}
