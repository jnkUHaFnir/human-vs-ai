#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    char input[20];
    int num;

    printf("Enter a number: ");
    fgets(input, sizeof(input), stdin);
    num = atoi(input);

    if ((num <= INT_MAX && num >= INT_MIN) || (num >= 0 && strncmp(input, "-", 1) != 0)) {
        printf("Input is within the range of an int.\n");
    } else {
        printf("Input is too large or too small for an int. Please re-enter.\n");
    }

    return 0;
}
