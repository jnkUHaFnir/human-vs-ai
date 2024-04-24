#include <stdio.h>
#include <stdlib.h>

int main() {
    int array[2][2], i, j;

    // Loop through each element in the 2D array
    for(i = 0; i < 2; ++i) {
        for(j = 0; j < 2; ++j) {
            printf("Value= ");
            scanf("%d", &array[i][j]); // Get user input and store it in the array

            // Check if the input is out of the desired range [-99, 99]
            if(array[i][j] < -99 || array[i][j] > 99) {
                printf("Input out of range. Exiting program.\n");
                exit(EXIT_FAILURE); // Exit the program if input is incorrect
            }
        }
    }

    // Print the result
    printf("Array contents:\n");
    for(i = 0; i < 2; ++i) {
        for(j = 0; j < 2; ++j) {
            printf("%d\t", array[i][j]);
        }
        printf("\n"); // Print a newline after each row for better formatting
    }

    return 0; // Exit the program successfully
}
