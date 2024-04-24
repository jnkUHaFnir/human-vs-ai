#include <stdio.h>
#include <stdlib.h>

void deldigit(char* str) {
    char* source = str; // Pointer to iterate through the string
    char* dest = str;   // Pointer to build a new string without digits

    // Loop over each character in the source string.
    while(*source != '\0') {
        // If the current character is not a digit, copy it to the destination
        if(!(*source >= '0' && *source <= '9')) { // Check range from '0' to '9'
            *dest = *source; 
            dest++; // Increment destination pointer
        }
        source++; // Always increment source pointer
    }

    // Null-terminate the processed string
    *dest = '\0';

    // Now, you can print the result here or return and print it in main
    printf("%s", str);
}

int main() {
    char str[100];

    printf("Insert word: ");
    scanf("%99s", str); // Use %99s to avoid buffer overflow, %s does not need &
    deldigit(str);

    return 0;
}
