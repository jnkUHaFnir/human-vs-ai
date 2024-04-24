#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <stdint.h>
#include <inttypes.h>

bool str_to_uint16(const char* str, uint16_t* res) {
    char* endptr;
    errno = 0;
    unsigned long val = strtoul(str, &endptr, 10);

    if (errno != 0 || *endptr != '\0' || val > UINT16_MAX) {
        return false;
    }

    *res = (uint16_t)val;
    return true;
}
#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>

unsigned int generate_seed() {
    unsigned int seed;
    int fd = open("/dev/urandom", O_RDONLY);
    if (fd < 0) {
        // Handle error
        exit(1);
    }
    if (read(fd, &seed, sizeof(seed)) != sizeof(seed)) {
        // Handle error
        close(fd);
        exit(1);
    }
    close(fd);
    return seed;
}

int main() {
    srand(generate_seed());
    // Your code here
    return 0;
}
