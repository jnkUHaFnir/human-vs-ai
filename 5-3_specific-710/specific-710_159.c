#include <stdio.h>
#include <limits.h>

int main() {
    long long userInput;
    
    printf("Enter a number: ");
    if (scanf("%lld", &userInput) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        return 1;
    }
    
    if (userInput > INT_MAX || userInput < INT_MIN) {
        printf("Input value is out of range for int. Please re-enter a valid number.\n");
    } else {
        int intValue = (int)userInput; // Convert to int
        printf("The input value fits within the range of int: %d\n", intValue);
    }
    
    return 0;
}
