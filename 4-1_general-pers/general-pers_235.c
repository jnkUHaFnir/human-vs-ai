#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int is_valid_password(const char* password) {
    int has_dollar = 0, has_digit = 0, has_upper = 0;
    
    while (*password) {
        if (isupper(*password)) {
            has_upper = 1;
        } else if (isdigit(*password)) {
            has_digit = 1;
        } else if (*password == '$') {
            has_dollar = 1;
        }
        
        if (has_dollar && has_digit && has_upper) {
            return 1;
        }
        
        password++;
    }
    
    return 0;
}

int main() {
    char *password = NULL;
    size_t len = 0;

    printf("Enter Password: ");
    
    if (getline(&password, &len, stdin) == -1) {
        printf("Error reading password\n");
        return 1;
    }

    // Remove the newline character from the entered password
    password[strcspn(password, "\n")] = 0;

    if (is_valid_password(password)) {
        printf("Good password!\n");
    } else {
        printf("BAD PASSWORD\n");
    }

    free(password);
    
    return 0;
}
