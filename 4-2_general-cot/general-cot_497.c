#include <stdio.h>

void deldigit(char* str) {
    char* result = str; // Pointer to track the modified string
    while(*str) {
        if(*str < '0' || *str > '9') {
            *result = *str;
            result++;
        }
        str++;
    }
    *result = '\0'; // Add null terminator after modifying the string
    printf("%s", str); // Print the modified string from the original pointer
}

int main() {
    char str[100];

    printf("Insert word: ");
    scanf("%s", str);
    deldigit(str);

    return 0;
}
