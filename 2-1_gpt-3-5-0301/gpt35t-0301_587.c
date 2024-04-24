#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int parse_hex(const char* str, int offset)
{
    char hex[5] = {0};
    int num;

    // Copy the hex characters to a temporary buffer
    for (int i = 0; i < 4; i++) {
        char c = tolower(str[offset + i]);
        if (!isxdigit(c)) {
            fprintf(stderr, "Error: Invalid hex character '%c'\n", c);
            exit(1);
        }
        hex[i] = c;
    }

    // Convert the hex string to an integer
    if (sscanf(hex, "%x", &num) != 1) {
        fprintf(stderr, "Error: Failed to parse hex string '%s'\n", hex);
        exit(1);
    }

    return num;
}
int main()
{
    const char* str = "foo10a4bar";
    int num = parse_hex(str, 3);
    printf("%d\n", num);
    return 0;
}
4260
