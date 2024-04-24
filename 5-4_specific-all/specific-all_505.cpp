#include <iostream>
#include <vector>

int main() {
    const int size = 1000000000;
    const int chunk_size = 1024; // Chunk size to grow geometrically
    std::vector<int> b;
    b.reserve(chunk_size); // Start with an initial capacity

    for (int i = 0; i < size; ++i) {
        if (b.size() == b.capacity()) {
            b.reserve(b.capacity() + chunk_size); // Grow geometrically
        }
        b.push_back(i);
    }

    return 0;
}
