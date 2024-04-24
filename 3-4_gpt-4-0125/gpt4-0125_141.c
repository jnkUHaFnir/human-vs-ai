bool all_zeros(const char *array, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (array[i] != 0) {
            return false;
        }
    }
    return true;
}
#include <emmintrin.h> // For SSE2
bool all_zeros_simd(const char *array, size_t size) {
    const __m128i zeros = _mm_setzero_si128();
    for (size_t i = 0; i < size; i += 16) {
        __m128i data = _mm_loadu_si128((__m128i*)(array + i));
        if (_mm_movemask_epi8(_mm_cmpeq_epi8(data, zeros)) != 0xFFFF) {
            return false;
        }
    }
    return true;
}
bool all_zeros_by_word(const char *array, size_t size) {
    size_t i = 0;
    // Check byte by byte until the array is aligned to word size.
    for (; (i < size) && ((uintptr_t)(array + i) & (sizeof(size_t) - 1)) != 0; ++i) {
        if (array[i] != 0) return false;
    }

    // Check word by word.
    for (; i + sizeof(size_t) <= size; i += sizeof(size_t)) {
        if (*(size_t*)(array + i) != 0) return false;
    }

    // Check any remaining bytes.
    for (; i < size; ++i) {
        if (array[i] != 0) return false;
    }
    return true;
}
