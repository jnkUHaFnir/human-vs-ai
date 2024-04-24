#include <vector>

struct Data {
    int* buffer;
    size_t count;
};

Data* getVectorData() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // allocate memory
    int* buffer = new int[vec.size()];
    
    // copy vector data into buffer
    std::copy(vec.begin(), vec.end(), buffer);
    
    // create the return struct
    Data* data = new Data{buffer, vec.size()};
    
    return data;
}

int main() {
    Data* data = getVectorData();
    
    // use the data pointer...
    
    // don't forget to free the memory
    delete[] data->buffer;
    delete data;
    
    return 0;
}
