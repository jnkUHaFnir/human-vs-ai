#include <stdio.h>

int main() {
    int num, result;

    printf("Enter a number: ");
    result = scanf("%d", &num);

    while(result != 1) {
        printf("Invalid input. Please enter a number: ");
        getchar(); // clear the invalid input from the buffer
        result = scanf("%d", &num);
    }

    printf("You entered: %d\n", num);
    return 0;
}
