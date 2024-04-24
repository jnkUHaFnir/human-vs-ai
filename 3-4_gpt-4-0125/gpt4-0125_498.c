#include <stdio.h>
#include <stdlib.h>

void deldigit(char* str) {
    char* dest = str; // Use a separate pointer to mark where to write characters

    while(*str != '\0') {
        if(*str >= '0' && *str <= '9') { // Check for all digits, including '0'
            // Do nothing, just skip this character
        }
        else {
            // Write non-digit character to the output position and move the output position
            *dest = *str;
            dest++;
        }
        str++; // Always move to the next input character
    }

    *dest = '\0'; // Terminate the modified string
}

int main() {
    char str[100];

    printf("Insert word: ");
    // Use %99s to avoid overflow. & is also not needed with array name.
    scanf("%99s", str); 
    deldigit(str);

    // Print the modified string
    printf("%s\n", str);

    return 0;
}
