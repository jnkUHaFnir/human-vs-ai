#include <stdio.h>

int main() {
    int i = 0, j = 0;
    char letter;
    int array[1000];

    printf("Input letters to convert into integers (end with a non-letter character like '0'): ");
    do {
        scanf(" %c", &letter); // Read a single character
        if ((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z')) {
            array[i] = letter; // Store the character in the array
            i++;
        }
        else {
            break; // Exit the loop if a non-letter character is entered
        }
    } while (1);

    for (j = 0; j < i; j++) {
        if (array[j] == 'A' || array[j] == 'a')
            printf("2 1 ");
        else if (array[j] == 'B' || array[j] == 'b')
            printf("2 2 ");
        // Add more conditions for other letters as needed...
    }

    return 0;
}
