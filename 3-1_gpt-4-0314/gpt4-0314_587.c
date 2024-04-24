#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

bool parse_hex(const char *str, int offset, int *result) {
    const int HEX_LEN = 4;
    int value = 0;

    for (int i = offset; i < offset + HEX_LEN; i++) {
        char c = str[i];
        value <<= 4;
        
        if (isdigit(c)) {
            value += c - '0';
        } else if (isxdigit(c)) {
            value += toupper(c) - 'A' + 10;
        } else {
            return false; // Invalid input
        }
    }

    *result = value;
    return true;
}

int main() {
    const char *str = "foo10a4bar";
    int result;

    if (parse_hex(str, 3, &result)) {
        printf("%d\n", result); // Output: 4260
    } else {
        printf("Invalid input\n");
    }

    return 0;
}
