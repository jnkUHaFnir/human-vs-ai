#include <vector>

constexpr int GROWTH_FACTOR = 2;

int main(int argc, char * argv[]) {
    const int size = 1000000000;    
    std::vector<int> b;
    b.reserve(1); // Start with initial capacity 1

    for(int i = 0; i < size; i++) {
        b.push_back(i);
        
        if (b.capacity() == b.size()) {
            b.reserve(b.capacity() * GROWTH_FACTOR); // Exponential growth
        }
    }

    return 0;
}
