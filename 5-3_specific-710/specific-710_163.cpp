#include <iostream>
#include <vector>

struct Data {
    int* dataPtr;
    size_t count;
};

Data getData() {
    std::vector<int> numbers = {1, 2, 3, 4, 5}; // Example data in the vector

    Data result;
    result.dataPtr = numbers.data(); // Get a pointer to the data in the vector
    result.count = numbers.size(); // Get the count of elements in the vector

    return result;
}

int main() {
    Data result = getData();

    for (size_t i = 0; i < result.count; ++i) {
        std::cout << result.dataPtr[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}
