#include <iostream>
#include <cstring>

bool areAllBytesZero(const unsigned char* arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (arr[i] != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    unsigned char arr[] = {0, 0, 0, 0, 0}; // example array with all zeros
    size_t size = sizeof(arr) / sizeof(arr[0]);

    if (areAllBytesZero(arr, size)) {
        std::cout << "All bytes are zero" << std::endl;
    } else {
        std::cout << "Not all bytes are zero" << std::endl;
    }

    return 0;
}
