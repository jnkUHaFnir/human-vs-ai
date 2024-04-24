#include <stdio.h>

int main()
{
    int i = 0, j = 0;
    char array[1000]; // Changed the array type to char

    printf("Input letters to convert into integers: ");
    do {
        scanf(" %c", &array[i]); // Use %c for characters
        i++;
    } while(array[i-1] != '\n'); // Check the previous element, not the next one

    for(j = 0; j < i-1; j++) { // Correct the loop condition
        if (array[j] == 'A')
            printf("2 1 ");
        else if (array[j] == 'B')
            printf("2 2 ");
        // Add more conditions for other letters if needed
    }

    return 0;
}
