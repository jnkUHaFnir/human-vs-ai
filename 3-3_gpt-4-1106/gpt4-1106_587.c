#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>

int parse_hex_at_offset(const char *str, int offset, int *out_value) {
    // Check that the input string and output pointer are non-null
    if (str == NULL || out_value == NULL) return -1;

    // Move to the offset
    const char *hex_str = str + offset;

    // Check that there are at least 4 characters from this point
    for (int i = 0; i < 4; ++i) {
        if (!isxdigit(hex_str[i])) return -2;
    }

    // Use strtoll to convert the hex to integer. Pass NULL to endptr to ignore the remaining string.
    char buffer[5]; // Buffer to hold the extracted substring with a terminating null
    strncpy(buffer, hex_str, 4); // Copy the four hex characters
    buffer[4] = '\0'; // Ensure null-termination

    errno = 0; // Reset errno to detect strtol errors
    long int value = strtol(buffer, NULL, 16);
    if (errno) {
        // Handle possible overflow or other errors
        perror("Error converting hex to integer");
        return -3;
    }
    *out_value = (int)value; // Cast the long to an int (four hex digits should not overflow an int)

    return 0; // Success
}

int main() {
    const char *test_str = "foo10a4bar";
    int offset = 3;
    int value;

    int result = parse_hex_at_offset(test_str, offset, &value);
    if (result == 0) {
        printf("Parsed value: %d\n", value);
    } else {
        printf("Error parsing value. Error code: %d\n", result);
    }

    return 0;
}
