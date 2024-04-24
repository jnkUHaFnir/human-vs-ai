#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[128];

    int match = scanf("%127[0-9A-Za-z]", name); // You should specify the maximum number of characters to read to prevent buffer overflow
    name[127] = '\0'; // Ensure the string is null-terminated

    if (match == 1 && strspn(name, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") == strlen(name)) {
        printf("Matched: %s", name);
    } else {
        printf("Invalid");
    }

    return 0;
}
