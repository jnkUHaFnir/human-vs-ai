#include <iostream>
#include <vector>

// Define a struct to hold the pointer to data and count
struct DataWithCount {
    int* data;
    size_t count;
};

DataWithCount getDataWithCount() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Create a struct to hold data pointer and count
    DataWithCount result;
    result.data = vec.data();
    result.count = vec.size();

    // Return the struct
    return result;
}

int main() {
    DataWithCount data = getDataWithCount();

    // Access the data and count outside the function
    for (size_t i = 0; i < data.count; i++) {
        std::cout << data.data[i] << " ";
    }

    // Clean up the data if needed
    // delete[] data.data; // Uncomment this line if memory needs to be freed manually

    return 0;
}
