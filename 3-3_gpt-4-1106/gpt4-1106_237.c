#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert(char **str, char input, int *n) {
    size_t newSize = *n + 2; // +1 for new character, +1 for null terminator
    char *newStr = realloc(*str, newSize);
    if (!newStr) {
        // Handle realloc failure
        printf("Failed to reallocate memory\n");
        return;
    }
    // Shift the original string to the right by one position
    memmove(newStr + 1, newStr, *n);
    // Insert the new character at the beginning
    newStr[0] = input;
    // Null-terminate the string
    newStr[*n + 1] = '\0';
    // Update pointer and size
    *str = newStr;
    (*n)++;
}

int main(void) {
    char *str;
    int n;
    char input;
    printf("How many characters do you want to input: ");
    scanf("%d", &n);
    str = malloc(n + 1); // +1 for null terminator
    if (!str) {
        printf("Failed to allocate memory\n");
        return 1;
    }
    printf("Input the string: ");
    scanf("%s", str);

    printf("The string is: %s\n", str);

    // Example usage
    printf("What is the character you want to insert: ");
    scanf(" %c", &input);
    insert(&str, input, &n);
    printf("Resulting string: %s\n", str);

    free(str); // Don't forget to free the memory
    return 0;
}
