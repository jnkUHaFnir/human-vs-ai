#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char *password = NULL;
    int x = 0;
    int y = 0;
    int z = 0;

    printf("Enter Password: "); 
    scanf("%m[^\n]", &password); // Read the input until newline, allowing spaces in the password

    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            x++;
        }
        if (isdigit(password[i])) {
            y++;
        }
        if (password[i] == '$') {
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
