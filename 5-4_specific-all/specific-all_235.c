#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    char *password = NULL;
    size_t index = 0;
    int x = 0, y = 0, z = 0;

    printf("Enter Password: ");
    
    // Dynamically allocate memory for password
    password = (char *)malloc(1000 * sizeof(char)); // You can adjust the initial size

    if (password == NULL) {
        printf("Memory allocation failed");
        return 1;
    }

    if(scanf("%999s", password) != 1) {
        printf("Failed to read password");
        free(password);
        return 1;
    }

    while (password[index] != '\0') {
        if (isupper(password[index])) {
            x++;
        } else if (isdigit(password[index])) {
            y++;
        } else if (password[index] == '$') {
            z++;
        }
        index++;
    }

    if (index == strlen(password) && x > 0 && y > 0 && z > 0) {
        printf("Good password!\n");
    } else {
        printf("BAD PASSWORD\n");
    }

    free(password);
    return 0;
}
