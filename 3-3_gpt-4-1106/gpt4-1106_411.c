#include <stdio.h>
#include <ctype.h>

void shift(char *my_string); // Function declaration

int main() {
    char inputstring[50];

    printf("Enter a string: ");
    fgets(inputstring, 50, stdin);  // Read the input here

    // Remove newline character if present
    inputstring[strcspn(inputstring, "\n")] = 0;

    shift(inputstring); // Call the shift function

    return 0;
}

void shift(char *my_string) { // Function definition
    int i = 0;
    int toUpper = isupper(my_string[0]);  // Check the case of the first character
    
    while (my_string[i]) {
        if (toUpper) {
            putchar(toupper(my_string[i]));  // Convert to upper case
        } else {
            putchar(tolower(my_string[i]));  // Convert to lower case
        }
        i++;
    }
    putchar('\n'); // Add a newline character at the end
}
