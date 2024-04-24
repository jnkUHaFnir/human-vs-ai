#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    char *password = NULL;
    int x = 0, y = 0, z = 0;
    size_t index = 0;

    printf("Enter Password: ");
    
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        char *temp = (char *)realloc(password, index + 1); // Allocate memory for one more character

        if (temp == NULL) {
            free(password);
            printf("Memory allocation failed. Exiting...\n");
            return 1;
        }

        password = temp;
        password[index++] = c;
    }

    password[index] = '\0'; // Null-terminate the string

    for (size_t i = 0; i < index; i++) {
        if (isupper(password[i])) {
            x++;
        }
        else if (isdigit(password[i])) {
            y++;
        }
        else if (password[i] == '$') {
            z++;
        }
    }

    if (x > 0 && y > 0 && z > 0) {
        printf("Good password!\n");
    } else {
        printf("Bad password\n");
    }

    free(password); // Free dynamically allocated memory
    return 0;
}
