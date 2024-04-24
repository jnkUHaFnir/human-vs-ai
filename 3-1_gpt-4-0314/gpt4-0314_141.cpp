#include <iostream>
#include <cstring>
#include <nmmintrin.h> // (SSE4.2)

bool isAllZero(const unsigned char* data, size_t length) {
    // Align data to 16-byte boundary
    size_t offset = (16 - (reinterpret_cast<uintptr_t>(data) & 15)) & 15;
    if (length < offset) return true;
    data += offset;
    length -= offset;

    __m128i zeroVector = _mm_setzero_si128();
    
    size_t simdIterations = length / 16;
    for(size_t i = 0; i < simdIterations; ++i) {
        __m128i dataVector = _mm_load_si128(reinterpret_cast<const __m128i*>(data));
        if(!_mm_test_all_zeros(dataVector, zeroVector)) {
            return false;
        }
        data += 16;
    }

    length %= 16;
    
    // Check remaining bytes
    for (size_t i = 0; i < length; ++i)
        if (data[i] != 0) return false;

    return true;
}

int main() {
    unsigned char arr[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    if (isAllZero(arr, sizeof(arr))) {
        std::cout << "All bytes are zero" << std::endl;
    } else {
        std::cout << "Not all bytes are zero" << std::endl;
    }

    return 0;
}
#include <iostream>
#include <cstring>

bool isAllZero(const unsigned char* data, size_t length) {
    unsigned char zero[length];
    std::memset(zero, 0, length);
    return std::memcmp(data, zero, length) == 0;
}

int main() {
    unsigned char arr[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    if (isAllZero(arr, sizeof(arr))) {
        std::cout << "All bytes are zero" << std::endl;
    } else {
        std::cout << "Not all bytes are zero" << std::endl;
    }

    return 0;
}
