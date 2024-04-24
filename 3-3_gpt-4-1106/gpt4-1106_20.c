#include <stdbool.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

bool str_to_uint16(const char* str, uint16_t* res) {
    if (str == NULL || *str == '\0' || *str == '-') {
        // String is null, empty, or negative, which isn't allowed for uint16_t.
        return false;
    }

    // To correctly handle the conversion error, ensure errno is 0 beforehand.
    errno = 0;
    char* endptr;
    uintmax_t result = strtoumax(str, &endptr, 10);

    // Error checking
    if (errno == ERANGE || result > UINT16_MAX) {
        // Range error: the input number is too large for uint16_t.
        errno = 0;
        return false;
    }

    if (*endptr != '\0') {
        // The entire string was not converted, there were invalid trailing characters.
        errno = 0;
        return false;
    }

    // All checks passed, so it is safe to cast to uint16_t and store in *res.
    *res = (uint16_t)result;
    return true;
}
int main(int argc, char *argv[]) {
    uint16_t port;
    if (argc > 1 && str_to_uint16(argv[1], &port)) {
        printf("Port number is: %" PRIu16 "\n", port);
    } else {
        printf("Error: Invalid port number.\n");
        return 1;
    }

    // ... rest of your program

    return 0;
}
