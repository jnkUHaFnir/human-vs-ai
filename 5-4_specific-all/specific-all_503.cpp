#include <vector>

int main(int argc, char *argv[]) {
    const int size = 1000000000;
    std::vector<int> b;
    b.reserve(1); // Start with capacity 1

    int next_power = 1;
    for (int i = 0; i < size; i++) {
        b.push_back(i);
        
        if (b.capacity() == next_power) {
            next_power *= 2;
            b.reserve(next_power); // Double the capacity
        }
    }

    return 0;
}
