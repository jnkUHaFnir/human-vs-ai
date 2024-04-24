#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char *input(void)
{
    int n = 1; // We need 1 byte for the null terminator initially
    char *str = malloc(sizeof(char)); // Allocate initial memory
    if (str == NULL) return NULL; // Always check if malloc was successful
    char *strPtr = str; // Use a separate pointer to traverse the array
    char ch;
    while((ch = getchar()) != '\n' && ch != EOF) // Read character by character until newline or EOF
    {
        *strPtr = ch; // Store the read character
        n++; // Increase the count for the next character + null terminator
        char *temp = realloc(str, n * sizeof(char)); // Attempt to realloc
        if (temp == NULL) {
            free(str); // It's important to free memory if realloc fails
            return NULL;
        }
        str = temp; // Update str with the new pointer
        strPtr = str + n - 2; // Update strPtr to point to the newly added character
    }
    *strPtr = '\0'; // Null-terminate the string
    return str; // Return the pointer to the beginning of the string
}

int main(int argc, char const *argv[])
{
    char *str = input();
    if (str != NULL) {
        printf("%s\n",str);
        free(str); // Don't forget to free the allocated memory
    } else {
        printf("Failed to allocate memory.\n");
    }
    return 0;
}
