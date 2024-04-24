#include <vector>
#include <cstring> // For std::memcpy

extern "C" { // For C linkage, adjust depending on the target language.

const int* copyVectorData(const std::vector<int>& vec, size_t* outCount) {
    *outCount = vec.size();
    int* rawData = new int[vec.size()];
    std::memcpy(rawData, vec.data(), vec.size() * sizeof(int));
    return rawData;
}

} // extern "C"
