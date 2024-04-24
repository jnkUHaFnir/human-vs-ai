#include <immintrin.h>

bool isAllBytesZero(const unsigned char* array, size_t size)
{
    static_assert(std::is_same<unsigned char, __m128i>::value, "Expected __m128i type to be unsigned char");

    const __m128i zeroVector = _mm_setzero_si128();

    // Check if size is a multiple of 16 for SSE alignment
    if (size % 16 != 0)
    {
        return false;
    }

    for (size_t i = 0; i < size; i += 16)
    {
        // Load 16 bytes at a time
        const __m128i data = _mm_loadu_si128(reinterpret_cast<const __m128i*>(array + i));

        // Compare the loaded data with zero
        const __m128i comparison = _mm_cmpeq_epi8(data, zeroVector);

        // Check if any byte is non-zero
        if (_mm_movemask_epi8(comparison) != 0xFFFF)
        {
            return false;
        }
    }

    return true;
}
