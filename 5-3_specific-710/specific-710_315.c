#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned char n[3] = {1, 2, 3};
    int i;
    char result[100]; // Assuming a maximum of 100 bytes

    // Step 1: Convert each element to string representation
    for (i = 0; i < 3; i++) {
        sprintf(&result[i*3], "%03d", n[i]); // Using %03d to ensure each number is represented as 3 digits
    }

    // Step 2: Convert the final concatenated string to an integer
    int final_number = atoi(result);

    // Step 3: Print the resulting integer
    printf("%d\n", final_number);

    return 0;
}
