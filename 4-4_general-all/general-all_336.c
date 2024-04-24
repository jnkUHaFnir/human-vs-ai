#include <stdint.h>

uint32_t GetIP(const char *p) {
    if (!p) { // Check for null pointer
        return 0;
    }

    uint32_t dwIP = 0, dwIP_Part = 0;
    int partCount = 0;

    while (*p != '\0') {
        if (*p == '.' || !isdigit(*p)) {
            if (*p != '.') {
                // Invalid character in the input string
                return 0;
            }

            dwIP = (dwIP << 8) | dwIP_Part;
            dwIP_Part = 0;
            partCount++;

            if (partCount > 3) {
                // Input string has more than 4 parts
                return 0;
            }
        } else {
            dwIP_Part = (dwIP_Part * 10) + (*p - '0');
        }

        p++;
    }

    if (partCount != 3) {
        // Invalid number of parts in the input string
        return 0;
    }

    // Handle the last part of the IP address
    dwIP = (dwIP << 8) | dwIP_Part;

    return dwIP;
}
