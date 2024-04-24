#include <vector>

int main() {
    const int size = 1000000000;

    std::vector<int> b;
    b.reserve(1); // Start with a small capacity

    int capacity = 1;
    for (int i = 0; i < size; i++) {
        if (b.size() == capacity) {
            capacity *= 2; // Double the capacity
            b.reserve(capacity); // Reserve the new capacity
        }
        b.push_back(i);
    }

    return 0;
}
