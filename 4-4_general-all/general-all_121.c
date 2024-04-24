#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    char input[MAX_LEN];
    int any_integer;
    char any_string[30]; // Assuming 30 is the maximum length for the string
    float any_float;

    while (1) {
        printf("Please enter an integer, one word string, and a float in one line: ");
        
        if(fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error reading input.\n");
            return 1;
        }

        // Parse the input using sscanf
        if(sscanf(input, "%d %29s %f", &any_integer, any_string, &any_float) != 3) {
            printf("Invalid input format. Please try again.\n");
            continue;
        }

        // Validate integer and float
        if(any_integer < 0 || any_integer > 50) {
            printf("*** Invalid integer. Please enter a value between 1 and 50.\n");
            continue;
        }

        if(any_float < 0) {
            printf("*** Invalid float. Please enter a positive value.\n");
            continue;
        }

        // Process the string to remove non-alphabetic characters
        for(int i = 0; i < strlen(any_string); i++) {
            if(!isalpha(any_string[i])) {
                any_string[i] = ' '; // Replace non-alphabetic characters with space
            }
        }

        printf("Integer: %d, String: %s, Float: %.2f\n", any_integer, any_string, any_float);

        // Exit loop if user enters 999
        if (any_integer == 999) {
            break;
        }
    }

    return 0;
}
