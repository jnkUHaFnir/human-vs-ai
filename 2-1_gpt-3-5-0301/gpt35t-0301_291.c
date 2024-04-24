#include <stdio.h>
#include <ctype.h>

int main() {
    char name[128];
    int i, valid = 1;

    printf("Enter name: ");
    fgets(name, 128, stdin);

    for (i = 0; name[i] != '\0' && name[i] != '\n'; i++) {
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
