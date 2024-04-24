#include <vector>

int main() {
    const int size = 1000000000;
    std::vector<int> b;
    b.reserve(size); // Pre-allocate memory to reduce reallocations

    int next_power = 1;
    for (int i = 0; i < size; i++) {
        if (b.size() == next_power - 1) {
            next_power *= 2;
            b.reserve(next_power); // Increase capacity exponentially
        }
        b.push_back(i);
    }

    return 0;
}
