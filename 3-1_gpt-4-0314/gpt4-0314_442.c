#include <stdio.h>
#include <string.h>

int main() {
    char buffer[] = "int1:int2:string1\0string2\0string3";
    int len = sizeof(buffer);
    int index = 0;

    // Assuming the first 8 bytes are two int values, look for ':' separator.
    while (buffer[index] != ':') {
        index++;
    }
    index++;  // Move past the ':' separator.

    char *p = &buffer[index];

    while (index < len) {
        printf("String: %s\n", p);

        // Move the pointer to the next NUL char
        while(*p != '\0') {
            p++;
            index++;
        }

        // Move the pointer past the NUL char
        p++;
        index++;
    }

    return 0;
}
