#include <stdio.h>

int hexCharsToInt(const char* str, int offset) {
    char hex[5];
    hex[0] = str[offset];
    hex[1] = str[offset + 1];
    hex[2] = str[offset + 2];
    hex[3] = str[offset + 3];
    hex[4] = '\0';

    int result;
    if (sscanf(hex, "%x", &result) != 1) {
        fprintf(stderr, "Invalid input\n");
        return -1;
    }

    return result;
}

int main() {
    const char* str = "foo10a4bar";
    int result = hexCharsToInt(str, 3);
    if (result != -1) {
        printf("%d\n", result); // Output: 4260
    }

    return 0;
}
