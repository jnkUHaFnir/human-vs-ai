#include <iostream>
#include <vector>

// Function that creates a vector, fills it with data, and returns a pointer to the data with its count
std::pair<int*, size_t> processData() {
    std::vector<int> data = {1, 2, 3, 4, 5};

    // Access the data pointer and count
    return {data.data(), data.size()};
}

int main() {
    auto [ptr, count] = processData();
    
    for (size_t i = 0; i < count; i++) {
        std::cout << ptr[i] << " ";
    }

    return 0;
}
