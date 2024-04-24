#include <vector>

int main(int argc, char * argv[]) {
    const unsigned long long size = 1000000000;
    std::vector<int> b;

    // Geometric resizing logic similar to realloc for std::vector
    b.reserve(1);  // Start with initial capacity of 1
    int next_capacity = 2;  // Next capacity after current one is filled
    for(int i = 0; i < size; i++) {
        if (b.size() == b.capacity()) {
            b.reserve(next_capacity);
            next_capacity *= 2;
        }
        b.push_back(i);
    }

    return 0;
}
