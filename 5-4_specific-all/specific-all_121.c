#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[200];
    int any_integer;
    char any_string[30];
    float any_float;

    while(1) {
        printf("Please enter an integer, one word string, and a float in one line: ");
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "999\n") == 0) {
            printf("Exiting program...\n");
            break;
        }

        // Parsing the input
        sscanf(input, "%d %29s %f", &any_integer, any_string, &any_float);

        // Validate the inputs
        if(any_integer < 0 || any_integer > 50) {
            printf("*** Invalid integer. Please enter a value between 1 and 50.\n");
            continue;
        }

        if(any_float < 0) {
            printf("*** Invalid float. Please enter a positive value.\n");
            continue;
        }

        // Filter out non-character characters from the string
        int j = 0;
        for(int i = 0; any_string[i]; i++){
            if(isalpha(any_string[i])) {
                any_string[j++] = any_string[i];
            }
        }
        any_string[j] = '\0';

        // Print the validated inputs
        printf("Integer: %d, String: %s, Float: %.2f\n", any_integer, any_string, any_float);
    }

    return 0;
}
