#include <iostream>
#include <vector>

const int* getData(const std::vector<int>& vec, size_t& count) {
    count = vec.size();
    return vec.data();
}

int main() {
    std::vector<int> myVector = {1, 2, 3, 4, 5};
    size_t count;
  
    const int* dataPtr = getData(myVector, count);
  
    // Use the data pointer and count as needed, for example:
    for (size_t i = 0; i < count; ++i) {
        std::cout << dataPtr[i] << " ";
    }
  
    return 0;
}
