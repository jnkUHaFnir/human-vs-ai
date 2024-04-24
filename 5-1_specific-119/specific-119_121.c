#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char input[200];
    int any_integer;
    char any_string[30];
    float any_float;

    while (1) {
        printf("Please enter an integer, one word string, and a float in one line (or enter 999 to exit): ");
        fgets(input, sizeof(input), stdin);
        
        // Parse the input
        if (sscanf(input, "%d %29s %f", &any_integer, any_string, &any_float) == 3) {
            // Check integer validity
            if (any_integer < 0 || any_integer > 50) {
                printf("\n*** Invalid integer. Please enter a value between 0 and 50.\n");
                continue;
            }
            
            // Check float validity
            if (any_float < 0) {
                printf("\n*** Invalid float. Please enter a positive value.\n");
                continue;
            }
            
            // Process the string to ignore non-alphabetic characters
            for (int i = 0; i < strlen(any_string); i++) {
                if (!isalpha(any_string[i])) {
                    any_string[i] = '\0';
                    break;
                }
            }

            printf("Integer: %d, String: %s, Float: %.2f\n", any_integer, any_string, any_float);
        } else if (any_integer == 999) {
            break; // Exit the loop if 999 is entered
        } else {
            printf("\n*** Invalid input format. Please enter an integer, one word string, and a float in one line.\n");
        }
    }

    return 0;
}
