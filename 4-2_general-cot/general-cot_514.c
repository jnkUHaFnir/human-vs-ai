#include <stdio.h>

int main() {
    int x;
    int previousInput = ' ';
    int input;
    
    while ((input = getchar()) != EOF) {
        if (input == ' ' && previousInput == ' ') {
            // Handle the case of two consecutive whitespaces
            printf("Two consecutive whitespaces found - Do something different here\n");
        } else if (input == ' ') {
            // Handle case of single whitespace
            printf("Single whitespace found - Do something here\n");
        } else {
            // Handle other characters
            printf("Non-whitespace character found - Do something here\n");
        }
        
        previousInput = input;
    }
    
    return 0;
}
