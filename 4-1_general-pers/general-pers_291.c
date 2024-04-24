#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[128];

    printf("Enter input: ");
    fgets(name, sizeof(name), stdin);

    // Remove newline character if present
    name[strcspn(name, "\n")] = '\0';

    int valid = 1;
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isalnum(name[i])) {
            valid = 0;
            break;
        }
    }

    if (valid) {
        printf("Matched\n");
    } else {
        printf("Invalid\n");
    }

    return 0;
}
