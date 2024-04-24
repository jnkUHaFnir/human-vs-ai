#include <stdio.h>
#include <stdlib.h>

void deldigit(char* str) {
    char* original_str = str;
    int count = 0;

    while (*str) {
        if (*str >= '0' && *str <= '9') {
            str++;
            count++;
        } else {
            *(str - count) = *str; /* Overwrite by skipping digits */
            str++;
        }
    }

    *(str - count) = '\0';
    printf("%s", original_str); // Print the modified string from the original pointer
}

int main() {
    char str[100];

    printf("insert word: ");
    scanf("%s", str);
    deldigit(str);

    return 0;
}
