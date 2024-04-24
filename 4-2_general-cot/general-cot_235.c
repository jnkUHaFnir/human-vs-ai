#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    char* password = NULL;
    int x = 0;
    int y = 0;
    int z = 0;

    printf("Enter Password: "); //Mike$4
    scanf("%ms", &password); // %ms allocates memory to store the input string

    for (int index = 0; index < strlen(password); index++) {
        if (isupper(password[index])) {
            x++;
        } else if (isdigit(password[index])) {
            y++;
        } else if (password[index] == '$') {
            z++;
        }
    }

    if (x > 0 && y > 0 && z > 0) {
        printf("Good password!\n");
    } else {
        printf("BAD PASSWORD\n");
    }

    free(password); // Free the dynamically allocated memory

    return 0;
}
