#include <stdio.h>
#include <string.h>

int startsWith(const char *str, const char *prefix) {
    while (*prefix) {
        if (*str != *prefix) {
            return 0;
        }
        str++;
        prefix++;
    }
    return 1;
}

int main() {
    char re[size_data];
    strncpy(re, data, size_data); // data is the buffer and size_data the buffer size

    // Find the first word in the packet
    char firstWord[5]; // Assuming the maximum length of the first word is 4 characters for "POST"
    sscanf(re, "%4s", firstWord);

    if (startsWith(firstWord, "POST")) {
        // *Something happens*
        printf("Packet starts with POST\n");
    }

    return 0;
}
