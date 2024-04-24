#include <iostream>
#include <vector>

// Function that returns a pointer to the data in a std::vector
const int* getDataPtr(const std::vector<int>& vec, size_t& size) {
    size = vec.size(); // Assign the size of the vector

    return (size > 0) ? vec.data() : nullptr;
}

int main() {
    std::vector<int> myVec = {1, 2, 3, 4, 5};
    size_t dataSize;

    const int* dataPtr = getDataPtr(myVec, dataSize);

    if (dataPtr) {
        // Use the data as needed
        for (size_t i = 0; i < dataSize; ++i) {
            std::cout << dataPtr[i] << " ";
        }
    } else {
        std::cout << "Vector is empty!";
    }

    return 0;
}
