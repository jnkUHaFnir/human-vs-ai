#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int any_integer;
    char any_string[30];
    float any_float;

    while(1) {
        printf("Please enter an integer, a string, and a float in one line: ");
        fgets(input, sizeof(input), stdin);
        
        if (strcmp(input, "999\n") == 0) { // check for termination condition
            break;
        }

        sscanf(input, "%d %29s %f", &any_integer, any_string, &any_float);

        /* Test the input */
        while(any_integer < 0 || any_integer > 50) {
            printf("\n*** Invalid integer. Please enter a value between 1 and 50: ");
            scanf("%d", &any_integer);
        }

        while(any_float < 0) {
            printf("\n*** Invalid float. Please enter a positive value: ");
            scanf("%f", &any_float);
        }

        // Ignore non-character characters in the string
        for(int i = 0; i < strlen(any_string); i++) {
            if((any_string[i] >= 'A' && any_string[i] <= 'Z') || (any_string[i] >= 'a' && any_string[i] <= 'z')) {
                // valid character
            } else {
                any_string[i] = '\0'; // replace non-character characters with null terminator
            }
        }

        printf("Integer: %d, String: %s, Float: %.2f\n", any_integer, any_string, any_float);
    }

    return 0;
}
