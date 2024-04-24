#include <stdio.h>

int main() {
    int i = 0, j = 0;
    char array[1000];

    printf("Input letters to convert into integers: ");
    do {
        scanf(" %c", &array[i]); // Use %c to read characters
        i++;
    } while(array[i-1] != '\n'); // Check for end-of-line correctly

    for (j = 0; j < i-1; j++) { // Loop up to i-1 to exclude the newline character
        if (array[j] == 'A') {
            printf("2 1 ");
        } else if (array[j] == 'B') {
            printf("2 2 ");
        }
        // Add more conditions for other letters as needed
    }

    return 0;
}
