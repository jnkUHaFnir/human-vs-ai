#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int main(void) {
    char username[SIZE][SIZE]; // Fixed memory allocation

    /* Read words into array */
    for (int i = 0; i < SIZE; i++) {
        scanf("%99s", username[i]); // Limit input size and read whitespace-separated words
    }

    /* Print out array */
    for (int p = 0; p < SIZE; p++) {
        printf("%s\n", username[p]); // Print a newline after each word
    }

    return 0;
}
