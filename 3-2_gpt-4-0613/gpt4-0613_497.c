#include <stdio.h>
#include <stdlib.h>

void deldigit(char* str) {
    int count = 0;
    char* start_ptr = str; // Save starting address for later use

    while(*str != '\0') {
        if(*str >= '0' && *str <= '9') // Include '0' as well
            count++;
        else
            *(str - count) = *str; // Overwrite characters
        str++;
    }

    *(str - count) = '\0'; // Place null character at end
    printf("%s", start_ptr); // Print from starting address
}

int main() {
    char str[100];

    printf("Insert word: ");
    scanf("%s", str);
    deldigit(str);

    return 0;
}
