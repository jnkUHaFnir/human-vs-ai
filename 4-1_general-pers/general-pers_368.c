#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool isFloat(char* str) {
    int dotCount = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-' && i != 0) {
            return false; // '-' is only allowed at the beginning
        } else if (str[i] == '.') {
            dotCount++;
            if (dotCount > 1) {
                return false; // more than one decimal point
            }
        } else if (str[i] < '0' || str[i] > '9') {
            return false; // non-digit character
        }
    }
    return true;
}

int main() {
    char input_str[100];
    double floatnum;

    printf("Enter a floating number num: ");
    fgets(input_str, sizeof(input_str), stdin);

    input_str[strcspn(input_str, "\n")] = 0; // remove trailing newline if present

    if (!isFloat(input_str)) {
        printf("Invalid floating point number, enter again.\n");
    } else {
        floatnum = strtod(input_str, NULL);
        printf("Number entered = %.2f\n", floatnum);
    }

    return 0;
}
