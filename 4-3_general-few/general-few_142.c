#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 8; // initial number of elements
    int *data = (int*)malloc(sizeof(int) * n);
    // Fill input data (sorted integers in this case)
    for (int i = 0; i < n; i++) {
        data[i] = i + 1;
    }

    while (n > 1) {
        int* newData = (int*)malloc(sizeof(int) * (n / 2));
        for (int i = 0; i < n / 2; i++) {
            newData[i] = data[2 * i] + data[2 * i + 1];
            printf("%d ", newData[i]); // Print the intermediate values
        }
        free(data); // Free the memory of the previous array
        data = newData;
        n /= 2; // Update the number of elements
        printf("\n");
    }

    // Print the final result
    printf("Final result: %d\n", data[0]);

    free(data); // Free the memory of the final array
    return 0;
}
