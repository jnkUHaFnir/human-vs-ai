#include <stdio.h>

int main()
{
    int i = 0, j = 0;
    char array[1000];

    // Input letters to convert into integers
    printf("Input letters to convert into integers: ");
    do {
        scanf(" %c", &array[i]);
        i++;
    } while(array[i-1] != '\n');

    // Convert letters into integers
    for (j = 0; j < i-1; j++) {
        if (array[j] == 'A')
            printf("2 1 ");
        else if (array[j] == 'B')
            printf("2 2 ");
        // Add more cases for other letters here
    }

    return 0;
}
