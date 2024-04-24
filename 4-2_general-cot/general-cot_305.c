#include <stdio.h>

int main() {
    int num;
    printf("Please enter a number: ");
    
    // Check if the input is a number
    if (scanf("%d", &num) == 1) {
        printf("You entered a valid number: %d\n", num);
    } else {
        printf("Invalid input. Please enter a valid number.\n");
    }
    
    return 0;
}
