#include <vector>

// Custom function to grow the vector geometrically
void growGeometrically(std::vector<int>& vec, size_t new_size) {
    if (new_size <= vec.capacity()) {
        return; // No need to resize
    }
    
    size_t new_capacity = vec.capacity();
    while (new_capacity < new_size) {
        new_capacity *= 2;
    }
    
    vec.reserve(new_capacity);
}

int main(int argc, char *argv[]) {
    const int size = 1000000000;
    std::vector<int> b;
    
    // Emulating geometric growth
    growGeometrically(b, size);
    
    for (int i = 0; i < size; ++i) {
        b.push_back(i);
    }

    return 0;
}
