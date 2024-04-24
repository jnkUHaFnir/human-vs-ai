#include <vector>

int main(int argc, char *argv[]) {
    const unsigned long long size = 1000000000;

    std::vector<int> b;
    b.reserve(size); // Preallocate memory to avoid multiple reallocations
    for (int i = 0; i < size; i++) {
        b.push_back(i);
    }

    return 0;
}
