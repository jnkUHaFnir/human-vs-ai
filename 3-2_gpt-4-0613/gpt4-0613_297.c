#include <stdio.h>

int main() {
    const int MAX_SIZE = 100;
    int histogram[MAX_SIZE];
    int i, size, status;

    while (1) {
        status = scanf("%d", &size);

        // Check for EOF or input error
        if (status == EOF || status != 1) {
            printf("Input error. Exiting program.\n");
            break;
        }

        if (size > 100 || size < 0) {
            printf("Invalid size. Enter a number between 0 and 100.\n");
            break;
        }

        // Check for EOF or input error during array input
        for (i = 0; i < size; i++) {
            status = scanf("%d", &histogram[i]);
            if (status == EOF || status != 1) {
                printf("Input error at index %d. Exiting program.\n", i);
                return 0;
            }
        }

        // Print and do whatever you want
        printf("Input accepted\n");
    }

    return 0;
}
