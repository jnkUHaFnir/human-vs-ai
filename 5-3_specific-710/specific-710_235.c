#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    char* password = NULL;
    int x = 0;
    int y = 0;
    int z = 0;

    printf("Enter Password: "); // Example: Mike$4

    // Dynamically allocate memory for the password
    size_t buffer_size = 10; // Initial buffer size
    size_t index = 0;
    password = (char*)malloc(buffer_size * sizeof(char));
    if (password == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (index >= buffer_size - 1) {
            buffer_size *= 2; // Double the buffer size
            password = (char*)realloc(password, buffer_size * sizeof(char));
            if (password == NULL) {
                printf("Memory reallocation failed.");
                free(password);
                return 1;
            }
        }

        password[index] = (char)c;

        if (isupper(password[index])) {
            x++;
        } else if (isdigit(password[index])) {
            y++;
        } else if (password[index] == '$') {
            z++;
        }
        
        index++;
    }

    password[index] = '\0'; // Null-terminate the string

    // Password validation
    if (x > 0 && y > 0 && z > 0) {
        printf("Good password!\n");
    } else {
        printf("BAD PASSWORD\n");
    }

    // Free dynamically allocated memory
    free(password);

    return 0;
}
