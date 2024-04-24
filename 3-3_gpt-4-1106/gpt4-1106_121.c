#include <stdio.h>
#include <ctype.h>

int main() {
    int any_integer;
    char any_string[30];
    float any_float;

    printf("Please enter an integer, one word string, and a float in one line:\n");

    // Reading integer, string and float in one line
    scanf("%i %29s %f", &any_integer, any_string, &any_float);

    // Putting this under an infinite loop
    while (1) {
        // Check for termination condition
        if (any_integer == 999) {
            printf("Termination code detected. Exiting program.\n");
            break;
        }

        // Test and correct the integer
        while (any_integer < 0 || any_integer > 50) {
            printf("\n*** Invalid integer.\nPlease enter a value between 0 and 50: ");
            scanf("%i", &any_integer);
            if (any_integer == 999) {
                printf("Termination code detected. Exiting program.\n");
                return 0; // Make sure to exit the loop and program
            }
        }

        // Test and correct the float
        while (any_float < 0 || any_float > 50) {
            printf("\n*** Invalid float.\nPlease enter a positive value not above 50: ");
            scanf("%f", &any_float);
        }

        // Filtering non-alphabetic characters from the string
        for (int i = 0; any_string[i] != '\0'; ++i) {
            if (!isalpha((unsigned char)any_string[i])) {
                any_string[i] = ' ';
            }
        }

        // Outputting the filtered data
        printf("You entered integer: %d, string: %s, and float: %f\n", any_integer, any_string, any_float);
        // Prompt for next input
        printf("\nEnter a new set of values or 999 to terminate:\n");
        scanf("%i %29s %f", &any_integer, any_string, &any_float);
    }

    return 0;
}
