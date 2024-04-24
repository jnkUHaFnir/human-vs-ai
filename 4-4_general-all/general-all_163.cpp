#include <iostream>
#include <vector>
#include <memory>

std::pair<int*, size_t> getDataAndCount() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Create a new array on the heap and copy vector's data into it
    int* data = new int[vec.size()];
    std::copy(vec.begin(), vec.end(), data);

    return {data, vec.size()};
}

int main() {
    auto [data, count] = getDataAndCount();

    // Use the data and count
    for (size_t i = 0; i < count; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    // Don't forget to delete the allocated memory
    delete[] data;

    return 0;
}
