#include <stdio.h>

int main()
{
    int i = 0, j = 0;
    char letter;
    int array[1000];
    
    printf("Input letters to convert into integers: ");

    do {
        scanf(" %c", &letter); // Read a single character at a time
        array[i] = letter - 'A' + 1; // Convert letter to integer (assuming capital letters)
        i++;
    } while (letter != '\n');

    for (j = 0; j < i; j++) {
        if (array[j] >= 1 && array[j] <= 26) {
            printf("%d ", array[j]);
        } else {
            printf("Invalid input ");
        }
    }

    return 0;
}
