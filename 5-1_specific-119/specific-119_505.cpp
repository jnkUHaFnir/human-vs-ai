#include <vector>

int main(int argc, char *argv[]) {
    const unsigned long long size = 1000000000;
    
    std::vector<int> b;
    b.reserve(1); // Start with an initial capacity of 1

    for (unsigned long long i = 0; i < size; i++) {
        if (b.size() == b.capacity()) {
            b.reserve(b.capacity() * 2); // Double the capacity when needed
        }
        b.push_back(static_cast<int>(i));
    }

    return 0;
}
