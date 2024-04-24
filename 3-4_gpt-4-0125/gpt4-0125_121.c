#include <stdio.h>
#include <ctype.h>

int main(void) {
    int any_integer;
    char any_string[30]; // Array size 30 to hold the null terminator.
    float any_float;
    int input_status;

    while (1) { // Infinite loop
        printf("\nPlease enter an integer, one word string, and a float in one line: ");
        
        // Attempt to read the 3 inputs in one go
        input_status = scanf("%d %29s %f", &any_integer, any_string, &any_float);

        // Check if input format was incorrect (less than 3 successful inputs)
        if (input_status < 3) {
            printf("*** Invalid input.\n");
            
            // Clear the input buffer
            while (getchar() != '\n');
            continue; // Skip the rest of the loop and prompt again
        }

        // Loop termination condition
        if (any_integer == 999) break;

        // Integer validation
        while (any_integer < 0 || any_integer > 50) {
            printf("\n*** Invalid integer. Please enter a value between 1 and 50: ");
            scanf("%d", &any_integer);
            if (any_integer == 999) return 0; // Check for exit condition after re-prompt.
        }

        // Float validation
        while (any_float < 0 || any_float > 50) {
            printf("\n*** Invalid float. Please enter a value between 0 and 50: ");
            scanf("%f", &any_float);
        }

        // String validation for characters
        for (int i = 0; any_string[i] != '\0'; i++) {
            if (!isalpha(any_string[i])) { // Check if the character is not alphabetic
                printf("\n*** Invalid string. Contains non-character values.\n");
                break; // If non-character is found, print message and break the loop
            }
        }
        
        // Assuming you proceed with valid data, you could do something with it here
    }

    return 0;
}
