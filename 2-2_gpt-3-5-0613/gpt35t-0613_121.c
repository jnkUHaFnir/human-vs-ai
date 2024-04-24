#include <stdio.h>

int main() {
    char line[100];
    int any_integer;
    char any_string[30];
    float any_float;

    while (1) {
        printf("Enter an integer, a word, and a float in one line (separated by spaces): ");
        fgets(line, sizeof(line), stdin);
        
        int result = sscanf(line, "%d %29s %f", &any_integer, any_string, &any_float);
        
        if (result != 3) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        if (any_integer < 0 || any_integer > 50) {
            printf("Invalid integer. Please enter a value between 0 and 50.\n");
            continue;
        }
        
        if (any_float < 0) {
            printf("Invalid float. Please enter a positive value.\n");
            continue;
        }
        
        printf("Integer: %d\n", any_integer);
        printf("String: %s\n", any_string);
        printf("Float: %.2f\n", any_float);
        
        if (any_integer == 999) {
            break;
        }
    }

    return 0;
}
