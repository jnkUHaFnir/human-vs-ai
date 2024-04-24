#include <vector>

int main(int argc, char * argv[]) {
    const int size = 1000000000;
    const int growth_factor = 2;

    std::vector<int> b;
    b.reserve(1);  // Initial reservation

    int capacity = 1;
    
    for (int i = 0; i < size; i++) {
        if (b.capacity() == capacity) {
            b.reserve(capacity * growth_factor);
            capacity *= growth_factor;
        }
        b.push_back(i);
    }

    return 0;
}
