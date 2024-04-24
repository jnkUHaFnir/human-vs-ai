#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char *password = NULL; // Pointer to char
    int x = 0, y = 0, z = 0;

    printf("Enter Password: ");
    scanf("%m[^\n]%*c", &password); // Read input until newline character
    
    for (int i = 0; password[i]; i++) {
        if (isupper(password[i])) {
            x++;
        } else if (isdigit(password[i])) {
            y++;
        } else if (password[i] == '$') {
            z++;
        }
    }

    if (x > 0 && y > 0 && z > 0) {
        printf("Good password!\n");
    } else {
        printf("BAD PASSWORD\n");
    }

    free(password); // Free dynamically allocated memory

    return 0;
}
