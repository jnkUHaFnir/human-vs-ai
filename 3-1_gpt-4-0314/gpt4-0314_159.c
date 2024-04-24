#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

bool fits_in_integer(const char* str, int* value) {
    long tmp = strtol(str, NULL, 10);

    if (tmp >= INT_MIN && tmp <= INT_MAX) {
        *value = (int)tmp;
        return true;
    }

    return false;
}

int main() {
    char input[50];
    int intValue;

    while (1) {
        printf("Enter a number: ");
        fgets(input, sizeof(input), stdin);

        if (fits_in_integer(input, &intValue)) {
            printf("The entered value is: %d\n", intValue);
            break;
        } else {
            printf("Please enter a value within the range of an integer.\n");
        }
    }

    return 0;
}
