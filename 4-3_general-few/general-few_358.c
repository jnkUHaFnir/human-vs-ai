#include <stdio.h>

int main() {
    int i = 0, j = 0;
    char array[1000]; // Change from int to char for storing letters

    printf("Input letters to convert into integers: ");
    
    do {
        scanf(" %c", &array[i]); // Use %c for characters and use & for storing in an array
        i++;
    } while (array[i-1] != '\n'); // Check for the newline character

    for (j = 0; j < i - 1; j++) { // i - 1 because the newline character is not considered
        if (array[j] == 'A')
            printf("2 1 ");
        else if (array[j] == 'B')
            printf("2 2 ");
        // Add cases for other letters here
    }

    return 0;
}
