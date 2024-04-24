#include <vector>

int main(int argc, char * argv[]) {
    const unsigned long long size = 1000000000;
    const int initialCapacity = 1; // Initial capacity of 1

    std::vector<int> b;
    b.reserve(initialCapacity);

    for (unsigned long long i = 0; i < size; i++) {
        b.push_back(i);

        if (b.capacity() == b.size()) {
            // Double the capacity when it is about to be exhausted
            b.reserve(2 * b.capacity());
        }
    }

    return 0;
}
