#include <stdio.h>
#include <string.h>

int main() {
    int r = 2; // Number of rows
    int c = 3; // Number of columns
    int arr[r][c];

    char input[100];
    fgets(input, sizeof(input), stdin); // Read input line as a string

    int num;
    int count = 0;
    char* token = strtok(input, " "); // Tokenize the input string
    while (token != NULL) {
        if (sscanf(token, "%d", &num) == 1) { // Check if token is a valid integer
            if (count < r * c) {
                arr[count / c][count % c] = num; // Fill the array
                count++;
            }
        }
        token = strtok(NULL, " ");
    }

    if (count != r * c) {
        printf("Insufficient datapoints\n");
    } else {
        // Array is successfully filled
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
