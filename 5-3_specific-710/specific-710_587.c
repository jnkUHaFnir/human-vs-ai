#include <stdio.h>
#include <ctype.h>

int hexCharToInt(char c) {
    if (isdigit(c)) {
        return c - '0';
    } else {
        return tolower(c) - 'a' + 10;
    }
}

int parseHexToInt(const char *str, int offset) {
    if (str == NULL || offset < 0 || offset + 4 > strlen(str)) {
        fprintf(stderr, "Invalid input string or offset\n");
        return -1; // Signal error
    }

    int value = 0;
    for (int i = offset; i < offset + 4; i++) {
        char c = tolower(str[i]);
        if (!isxdigit(c)) {
            fprintf(stderr, "Invalid hex character found\n");
            return -1; // Signal error
        }
        value = (value << 4) | hexCharToInt(c);
    }

    return value;
}

int main() {
    const char *testString = "foo10a4bar";
    int offset = 3;

    int parsedValue = parseHexToInt(testString, offset);
    if (parsedValue != -1) {
        printf("%d\n", parsedValue);
    }

    return 0;
}
