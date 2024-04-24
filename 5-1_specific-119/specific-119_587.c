#include <stdio.h>
#include <ctype.h>

int hex_chars_to_int(const char *str, int offset) {
    char hex[5];
    int num;

    // Copy 4 characters starting from the given offset
    for (int i = 0; i < 4; i++) {
        hex[i] = toupper(str[offset + i]);
        if (!isxdigit(hex[i])) {
            return -1;  // Return -1 if invalid input
        }
    }
    hex[4] = '\0';  // Null-terminate the string

    // Convert hex string to integer
    sscanf(hex, "%x", &num);

    return num;
}

int main() {
    char *input = "foo10a4bar";
    int offset = 3;

    int result = hex_chars_to_int(input, offset);
    if (result != -1) {
        printf("Result: %d\n", result);
    } else {
        printf("Invalid input\n");
    }

    return 0;
}
