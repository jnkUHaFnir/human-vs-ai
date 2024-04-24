#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    char input[50];
    int userValue;
    bool validInput = false;

    while (!validInput) {
        printf("Enter an integer: ");
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &userValue) == 1) {
            if (userValue <= INT_MAX && userValue >= INT_MIN) {
                validInput = true;
            } else {
                printf("Input value exceeds the range of an int. Please re-enter.\n");
            }
        } else {
            printf("Invalid input. Please enter a valid integer.\n");
        }
    }

    printf("Input value: %d\n", userValue);

    return 0;
}
