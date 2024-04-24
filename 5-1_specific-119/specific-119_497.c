#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deldigit(char* str) {
    char* result = str;
    
    while(*str) {
        if(*str < '0' || *str > '9') {
            *result = *str;
            result++;
        }
        str++;
    }

    *result = '\0'; // Terminate string properly
    printf("%s", result);
}

int main() {
    char str[100];

    printf("Insert word: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character if present
    str[strcspn(str, "\n")] = 0;
    
    deldigit(str);

    return 0;
}
