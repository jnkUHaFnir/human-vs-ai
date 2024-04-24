#include <stdio.h>
#include <string.h>

int main() {
    int any_integer;
    char any_string[30];
    float any_float;
    
    while(1) {
        printf("Please enter an integer, one word string, and a float in one line: ");
        
        if(scanf("%d %29s %f", &any_integer, any_string, &any_float) != 3) {
            printf("Invalid input format. Please try again.\n");
            // Clear input buffer
            while(getchar() != '\n');
            continue;
        }
        
        // Test the input
        if(any_integer < 1 || any_integer > 50) {
            printf("*** Invalid integer. Please enter a value between 1 and 50.\n");
            continue;
        }
        
        if(any_float < 0) {
            printf("*** Invalid float. Please enter a positive value.\n");
            continue;
        }
        
        // Ignore everything that is not a character in the string
        for(int i = 0; i < strlen(any_string); i++) {
            if((any_string[i] < 'A' || any_string[i] > 'Z') && (any_string[i] < 'a' || any_string[i] > 'z')) {
                any_string[i] = ' ';
            }
        }
        
        printf("Integer: %d, String: %s, Float: %.2f\n", any_integer, any_string, any_float);
        
        if(any_integer == 999) {
            break;
        }
    }
    
    return 0;
}
