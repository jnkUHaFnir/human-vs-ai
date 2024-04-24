#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    // We start with a reasonable guess for initial allocation.
    int buff_size = 128;
    char *password = malloc(buff_size * sizeof(char));
    
    if (password == NULL) {
        printf("Failed to allocate memory\n");
        return 1;
    }

    printf("Enter Password: ");

    // fgets reads up to buff_size-1 characters; the last character is reserved for the null terminator
    if (fgets(password, buff_size, stdin) == NULL) {
        printf("Error reading password\n");
        free(password);
        return 1;
    }

    // Remove newline character if present
    password[strcspn(password, "\n")] = 0;

    // Using int variables to check the presence of requirements
    int has_upper = 0, has_digit = 0, has_dollar = 0;

    for (int i = 0; password[i]; i++) {
        if (isupper(password[i])) has_upper = 1;
        if (isdigit(password[i])) has_digit = 1;
        if (password[i] == '$') has_dollar = 1;
    }

    if (has_upper && has_digit && has_dollar) {
        printf("Good password!\n");
    } else {
        printf("BAD PASSWORD\n");
    }

    free(password);
    return 0;
}
