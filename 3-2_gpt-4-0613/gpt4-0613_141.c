#include <stdbool.h>

bool all_zero(const unsigned char* data, size_t len) {
    size_t i;
    const unsigned long* long_data = (const unsigned long*)data;

    for(i = 0; i < len / sizeof(long); ++i)
        if(long_data[i] != 0)
            return false;

    return true;
}

This is going to call the built-in function `all()` which returns True if all elements in the given iterable are true. In the given case, the iterable generates a True for each element equal to 0, otherwise it generates a False.
