#include <stdio.h>

int main() {
    int num;

    printf("Enter a number: ");
    
    if (scanf("%d", &num) == 1) {
        printf("You entered a valid number: %d\n", num);
    } else {
        printf("Invalid input. Please enter a valid number.\n");
    }

    return 0;
}
``` 

In this code snippet, scanf is used to read an integer into the variable num. The return value of scanf is checked. If it returns 1, then the input was successfully read as an integer.
