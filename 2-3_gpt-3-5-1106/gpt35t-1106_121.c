#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int any_integer;
    char any_string[30];
    float any_float;

    while (1) {
        printf("Please enter an integer, a word, and a float in one line: ");
        fgets(input, sizeof(input), stdin);

        // Parse the input using strtok
        char *token = strtok(input, " \n");
        any_integer = atoi(token);

        token = strtok(NULL, " \n");
        strcpy(any_string, token);

        token = strtok(NULL, " \n");
        any_float = atof(token);

        // Test the input
        if (any_integer == 999) {
            printf("Terminating the program...\n");
            break;
        } else if (any_integer < 0 || any_integer > 50) {
            printf("*** Invalid integer. Please enter a value between 0 and 50.\n");
            continue;
        } else if (any_float < 0) {
            printf("*** Invalid float. Please enter a positive value.\n");
            continue;
        } else {
            // Print the values
            printf("Integer: %d, String: %s, Float: %.2f\n", any_integer, any_string, any_float);
        }
    }

    return 0;
}
