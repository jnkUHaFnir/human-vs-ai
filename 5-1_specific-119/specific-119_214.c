#include <stdio.h>

int main() {
    char str[30];
    int size = 0;

    puts("Enter the string:");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') { // Check if the character is not a space
            size++;
        }
    }

    printf("Size of string without spaces: %d\n", size);

    return 0;
}
