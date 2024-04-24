#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert(char **str, char input, int n) {
    // You need to increase the size of your string to accommodate the new character
    *str = realloc(*str, n + 2); // +1 for new char, +1 for '\0'
    if (*str == NULL) { // Always check if realloc failed
        perror("Failed to resize the string");
        return;
    }
    
    // Move the existing string one position to the right to make space for new character
    memmove(*str + 1, *str, n + 1); // +1 to include '\0' at the end

    // Insert the new character
    (*str)[0] = input;

    // Since you've already resized your string and added the character,
    // there's no need to loop or use any further logic here.

    // No need to print here, can be done after function call
}

int main() {
    char *str;
    int n;
    char input;

    printf("How many characters do you want to input: ");
    scanf("%d", &n);
    str = malloc(n + 1); // +1 for '\0'
    if (str == NULL) { // Always check if malloc failed
        perror("Failed to allocate memory for the string");
        return 1;
    }
    printf("Input the string: ");
    scanf("%s", str);

    printf("The string is: %s\n", str);

    printf("What is the character you want to insert: ");
    scanf(" %c", &input); // Note the space before %c to consume the newline character
    insert(&str, input, n);

    printf("Resulting string: %s\n", str);

    // Don't forget to free the allocated memory
    free(str);

    return 0;
}
