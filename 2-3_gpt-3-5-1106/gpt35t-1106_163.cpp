#include <vector>

// Function to return a pointer to the data and count of a vector
std::pair<int*, int> getDataAndCount(const std::vector<int>& vec) {
    return {vec.data(), vec.size()};
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Get the pointer to the data and count from the vector
    auto [dataPtr, count] = getDataAndCount(vec);

    // Now you can use dataPtr and count as needed
    for (int i = 0; i < count; i++) {
        std::cout << dataPtr[i] << " ";
    }

    return 0;
}
