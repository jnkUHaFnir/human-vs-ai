#include <stdio.h>
#include <stdlib.h>

void insert(char *str, char input, int n);

int main() {
    int n;
    char *str;
    char input;
    
    printf("How many characters do you want to input: ");
    scanf("%d", &n);
    str = malloc(n + 2); // Allocate space for n characters plus the '\0' character
    
    printf("Input the string: ");
    scanf("%s", str);

    printf("Do you want to 1-insert or 2-remove or 3-quit?: ");
    char choice;
    scanf(" %c", &choice);
    
    switch(choice) {
        case '1':
            printf("What is the character you want to insert: ");
            scanf(" %c", &input);
            insert(str, input, n);
            break;
        default:
            break;
    }
    
    free(str); // Don't forget to free the allocated memory
    return 0;
}

void insert(char *str, char input, int n) {
    size_t space = n + 2; // Increase the space to n + 2 to include the null terminator
    str = realloc(str, space * sizeof(char));
    
    // Make room for inserting the character
    for (int i = n; i > 0; i--) {
        str[i] = str[i - 1];
    }
    
    str[0] = input; // Insert the new character at the beginning
    
    printf("Resulting string: %s\n", str);
}
