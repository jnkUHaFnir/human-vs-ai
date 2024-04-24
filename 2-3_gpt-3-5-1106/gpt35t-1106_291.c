#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[128];
    int i, valid = 1;

    printf("Enter a string: ");
    fgets(name, sizeof(name), stdin);

    for (i = 0; i < strlen(name) - 1; i++) {
        if (!isalnum(name[i])) {
            valid = 0;
            break;
        }
    }

    if (valid) {
        printf("Valid input\n");
    } else {
        printf("Invalid input\n");
    }

    return 0;
}
