#include <string.h>

void setMemoryToZeroUsingInt(int* ptr, size_t size) {
    size_t numInts = size / sizeof(int);
    for (size_t i = 0; i < numInts; ++i) {
        ptr[i] = 0;
    }
}

void setMemoryToZeroUsingChar(char* ptr, size_t size) {
    memset(ptr, 0, size);
}
