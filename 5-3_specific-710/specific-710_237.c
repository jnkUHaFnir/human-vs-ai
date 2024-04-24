#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert(char **str, char input, int n) {
    size_t len = strlen(*str);
    *str = realloc(*str, len + 2); // Increase the size of the array by 1 to accommodate the new character and null terminator
    
    memmove(*str + 1, *str, len); // Shift the existing characters to the right
    (*str)[0] = input; // Insert the new character at the beginning
    (*str)[len + 1] = '\0'; // Add null terminator at the end

    printf("Resulting string: %s\n", *str);
}

int main() {
    int n;
    char input;
    char *str;

    printf("How many characters do you want to input: ");
    scanf("%d", &n);
    str = malloc(n + 1);
    
    printf("Input the string: ");
    scanf("%s", str);

    printf("Do you want to 1-insert or 2-remove or 3-quit?: ");
    // Assuming you have code here to get user choice

    printf("What is the character you want to insert: ");
    scanf(" %c", &input);

    insert(&str, input, n);
    
    free(str); // Don't forget to free the allocated memory
    return 0;
}
