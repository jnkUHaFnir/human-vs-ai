#include <stdio.h>
#include <ctype.h>

int parseHexToInt(const char *str, int offset) {
    char hexStr[5];
    int value;

    if (offset < 0 || offset + 4 > strlen(str)) {
        fprintf(stderr, "Invalid offset\n");
        return -1;
    }

    strncpy(hexStr, str + offset, 4);
    hexStr[4] = '\0';

    for (int i = 0; i < 4; i++) {
        hexStr[i] = toupper(hexStr[i]);
        if (!isxdigit(hexStr[i])) {
            fprintf(stderr, "Invalid hex characters\n");
            return -1;
        }
    }

    sscanf(hexStr, "%x", &value);

    return value;
}

int main() {
    const char *str = "foo10a4bar";
    int offset = 3;
    int result = parseHexToInt(str, offset);
    if (result != -1) {
        printf("Parsed value: %d\n", result);
    }
    return 0;
}
