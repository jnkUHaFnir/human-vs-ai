#include <stdio.h>

int main() {
    int age;
    int status;

    do {
        printf("How old are you?\n");
        status = scanf("%d", &age);

        if (status != 1) { // If the input is not an integer
            printf("Error, invalid input. Please enter a number.\n");
                        
            // Clearing the input buffer
            while (getchar() != '\n');
        } else if (age < 0) { // You might want to check for reasonable age values
            printf("Error, age cannot be negative. Please try again.\n");
        } else {
            printf("Cool.\n");
            break;
        }
    } while (1); // Infinite loop that will only break when a valid age is entered

    return 0;
}
