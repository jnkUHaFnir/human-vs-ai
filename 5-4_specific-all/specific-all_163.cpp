#include <iostream>
#include <vector>

int* processData(std::vector<int>& myVector, size_t& count) {
    count = myVector.size(); // get the size of the vector
    
    return myVector.data(); // return a pointer to the vector's data
}

int main() {
    std::vector<int> myVector = {1, 2, 3, 4, 5};
    size_t count = 0;
    
    int* dataPtr = processData(myVector, count);
    
    // Use the pointer to access the data
    for (size_t i = 0; i < count; ++i) {
        std::cout << dataPtr[i] << " ";
    }
    
    std::cout << std::endl;
    
    return 0;
}
