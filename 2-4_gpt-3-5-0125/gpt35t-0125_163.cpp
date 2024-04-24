#include <iostream>
#include <vector>

struct Data {
    int* ptr;
    size_t size;
};

Data getDataFromVector(const std::vector<int>& vec) {
    Data data;
    data.ptr = vec.data();
    data.size = vec.size();
    return data;
}

int main() {
    std::vector<int> myVector = {1, 2, 3, 4, 5};
    Data data = getDataFromVector(myVector);

    // Access and print the elements using the pointer
    for (size_t i = 0; i < data.size; i++) {
        std::cout << data.ptr[i] << " ";
    }

    return 0;
}
