#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char input[100]; // Assuming input line will not exceed 100 characters
    int any_integer;
    char any_string[30];
    float any_float;

    while (1) {
        printf("Please enter an integer, one word string, and a float in one line (or enter '999' to exit): ");
        fgets(input, sizeof(input), stdin);

        // Exit if user inputs '999'
        if (strncmp(input, "999", 3) == 0) {
            break;
        }

        // Parse the input line
        if (sscanf(input, "%d %29s %f", &any_integer, any_string, &any_float) == 3) {
            // Input validation
            if (any_integer < 0 || any_integer > 50) {
                printf("\n*** Invalid integer. Please enter a value between 0 and 50.\n");
                continue;
            }
            if (any_float < 0) {
                printf("\n*** Invalid float. Please enter a positive value.\n");
                continue;
            }
            
            // Filtering unwanted characters in the string
            for(size_t i = 0; i < strlen(any_string); i++) {
                if (!isalpha(any_string[i])) {
                    any_string[i] = '\0'; // Replace non-alphabetic characters with null terminator
                }
            }

            printf("\nInteger: %d\nString: %s\nFloat: %.2f\n", any_integer, any_string, any_float);
        } else {
            printf("\nInvalid input format. Please enter an integer, one word string, and a float in the specified format.\n");
            continue;
        }
    }

    printf("Exiting the program. Goodbye!\n");

    return 0;
}
