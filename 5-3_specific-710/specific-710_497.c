#include <stdio.h>
#include <stdlib.h>

void deldigit(char* str) {
    char* result = str; // Use a separate pointer to keep track of the modified string
    int count = 0;

    while (*str != '\0') {
        if (*str >= '0' && *str <= '9') {
            count++;
        } else {
            *(result) = *str; // Use 'result' pointer to overwrite characters without numbers
            result++;
        }
        str++;
    }

    *result = '\0'; // Terminate the modified string correctly
    printf("%s", result);
}

int main() {
    char str[100];

    printf("insert word: ");
    scanf("%s", str);
    deldigit(str);

    return 0;
}
