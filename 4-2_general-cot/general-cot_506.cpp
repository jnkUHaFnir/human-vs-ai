#include <vector>

int main(int argc, char * argv[]) {
    const int size = 1000000000;
    std::vector<int> b;
    int capacity = 1; // Start with capacity 1
    b.reserve(capacity);

    for (int i = 0; i < size; i++) {
        if (b.size() == capacity) {
            capacity *= 2; // Double the capacity
            b.reserve(capacity);
        }
        b.push_back(i);
    }

    return 0;
}
