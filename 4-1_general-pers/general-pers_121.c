#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100

int main() {
    int any_integer;
    char any_string[30];
    float any_float;
    char input[MAX_LINE_LENGTH];

    printf("Please enter an integer, one word string, and a float in one line: ");

    while(fgets(input, MAX_LINE_LENGTH, stdin) != NULL) {
        if (strcmp(input, "999\n") == 0) {
            // Terminate the loop when input is 999
            break;
        }

        if (sscanf(input, "%d %29s %f", &any_integer, any_string, &any_float) == 3) {
            // Input successfully parsed into 3 variables

            // Validate integer and float
            if (any_integer < 0 || any_integer > 50) {
                printf("\n*** Invalid integer. Please enter a value between 1 and 50.\n");
                continue; // Restart the loop
            }

            if (any_float < 0) {
                printf("\n*** Invalid float. Please enter a positive value.\n");
                continue; // Restart the loop
            }

            // Remove non-alphabetic characters from the string
            size_t len = strlen(any_string);
            for (size_t i = 0; i < len; i++) {
                if (!isalpha(any_string[i])) {
                    any_string[i] = ' ';
                }
            }

            // Print the parsed values for testing
            printf("Integer: %d, String: %s, Float: %.2f\n", any_integer, any_string, any_float);
        } else {
            printf("\n*** Invalid input format. Please enter an integer, one word string, and a float in one line.\n");
        }
    }

    return 0;
}
