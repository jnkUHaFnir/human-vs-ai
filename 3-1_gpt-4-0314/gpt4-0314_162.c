#include <stdio.h>
#include <stdlib.h>

int main() {
    int array[2][2], i, j;
    int invalid_input = 0; // Add a flag to break the outer loop if input is out of boundaries

    for (i = 0; i < 2; ++i) {
        for (j = 0; j < 2; ++j) {
            printf("Value= ");
            scanf("%d", &array[i][j]);

            if (array[i][j] < -99 || array[i][j] > 99) {
                invalid_input = 1; // Set the flag if the input is out of boundaries
                break;
            }
        }
        if (invalid_input) // Break the outer loop if the flag is set
            break;
    }

    // If the input is invalid, print an error message and exit
    if (invalid_input) {
        printf("Invalid input. Value must be between -99 and 99.\n");
        exit(1);
    }

    // Print the result
    for (i = 0; i < 2; ++i) {
        for (j = 0; j < 2; ++j) {
            printf("[%d][%d]: %d\n", i, j, array[i][j]);
        }
    }

    return 0;
}
