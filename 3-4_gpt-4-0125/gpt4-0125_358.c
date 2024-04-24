#include <stdio.h>

int main() {
    int i = 0;
    char array[1000]; // Change to char array

    printf("Input letters to convert into integers: ");
    do {
        scanf(" %c", &array[i]); // Correct format specifier and add address-of operator
        if(array[i] == '\n') { // Check if the input is newline to break the loop
            break;
        }
        i++;
    } while(i < 999); // Make sure we don't overflow the array

    // End the string to help with processing (optional but often good practice)
    array[i] = '\0'; 

    for (int j = 0; j < i; j++) {
        if (array[j] == 'A')
            printf("2 1 ");
        else if (array[j] == 'B')
            printf("2 2 ");
        // and so on...
    }
    
    return 0;
}
