#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100]; // Adjust size as necessary
    int any_integer;
    char any_string[30];
    float any_float;

    while(1) {
        printf("Please enter an integer, one word string, and a float in one line (or enter 999 to quit): ");
        fgets(input, sizeof(input), stdin);

        if (strncmp(input, "999", 3) == 0) {
            printf("Exiting program.\n");
            break;
        }

        if (sscanf(input, "%d %29s %f", &any_integer, any_string, &any_float) != 3) {
            printf("Invalid input format. Please try again.\n");
            continue;
        }

        // Test the input
        while (any_integer < 1 || any_integer > 50) {
            printf("*** Invalid integer.\nPlease enter a value between 1 and 50: ");
            scanf("%d", &any_integer);
        }

        while (any_float < 0) {
            printf("*** Invalid float.\nPlease enter a positive value: ");
            scanf("%f", &any_float);
        }

        // Clear stdin
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        // Ignore any non-characters in the string
        for (int i = 0; any_string[i]; i++) {
            if (!isalpha(any_string[i])) {
                any_string[i] = ' ';
            }
        }

        printf("Integer: %d, String: %s, Float: %.2f\n", any_integer, any_string, any_float);
    }

    return 0;
}
