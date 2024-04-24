#include <stdio.h>

int main() {
    int number;
    printf("Please enter a number: ");

    // scanf returns the number of successful assignments
    if (scanf("%d", &number) == 1) {
        // if the return value is 1, then it read an integer successfully
        printf("You entered a number: %d\n", number);
    } else {
        // if the return value is not 1, then it didn't read an integer
        printf("You did not enter a number.\n");
    }
    return 0;
}
