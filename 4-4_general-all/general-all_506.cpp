#include <vector>
#include <iostream>

int main() {
    const unsigned long long size = 1000000000;
    
    std::vector<int> b;
    b.reserve(size); // Reserve memory upfront to avoid reallocation during addition
    
    for (unsigned long long i = 0; i < size; ++i) {
        b.push_back(i);
    }

    return 0;
}
