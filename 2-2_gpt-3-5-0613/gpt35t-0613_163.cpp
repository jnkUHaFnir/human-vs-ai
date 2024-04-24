#include <iostream>
#include <vector>

struct VectorData {
    int* ptr;
    size_t size;
};

VectorData getVectorData(std::vector<int>& vec) {
    return { vec.data(), vec.size() };
}

int main() {
    std::vector<int> vec { 1, 2, 3, 4, 5 };
    VectorData data = getVectorData(vec);
    
    std::cout << "Data: ";
    for (size_t i = 0; i < data.size; i++) {
        std::cout << data.ptr[i] << ' ';
    }
    
    return 0;
}
#include <iostream>
#include <memory>
#include <vector>

std::shared_ptr<int> getVectorData(std::vector<int>& vec) {
    return std::shared_ptr<int>(vec.data(), [](int*){});
}

int main() {
    std::vector<int> vec { 1, 2, 3, 4, 5 };
    std::shared_ptr<int> data = getVectorData(vec);
    
    std::cout << "Data: ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << data.get()[i] << ' ';
    }
    
    return 0;
}
