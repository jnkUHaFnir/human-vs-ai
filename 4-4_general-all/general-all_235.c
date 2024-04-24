#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    char *password = NULL;
    int index = 0;
    int x = 0;
    int y = 0;
    int z = 0;

    printf("Enter Password: ");
    
    // Dynamically allocate memory for password
    password = (char*)malloc(sizeof(char));
    if (password == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        password[index] = (char)c;
        password = (char*)realloc(password, (index + 2) * sizeof(char)); // Resize memory for password
        index++;
    }
    password[index] = '\0';

    do {
        if (index == strlen(password) && x > 0 && y > 0 && z > 0) {
            printf("Good password!\n");
            break;
        }
        if (index == strlen(password) && (x == 0 || y == 0 || z == 0)) {
            printf("BAD PASSWORD\n");
            break;
        }

        if (isupper(password[index]) || isdigit(password[index]) || password[index] == '$') {
            if (isupper(password[index])) {
                x++; index++;
                continue;
            }
            if (isdigit(password[index])) {
                y++; index++;
                continue;
            }
            if (password[index] == '$') {
                z++; index++;
                continue;
            }
        } else {
            index++;
            continue;
        }
    } while (index <= strlen(password));

    // Free dynamically allocated memory
    free(password);

    return 0;
}
