#include <vector>
#include <iostream>

int main(int argc, char* argv[]) {
    const int size = 1000000000;
    std::vector<int> b;

    for (int i = 0; i < size; i++) {
        b.push_back(i);
        if (i % 100000 == 0) {
            std::cout << "Capacity at index " << i << ": " << b.capacity() << std::endl;
        }
    }

    return 0;
}
