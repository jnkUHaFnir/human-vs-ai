#include <vector>

template <typename T>
void exponential_resize(std::vector<T>& v, size_t new_size) {
    if (new_size <= v.capacity()) {
        return; // No need to resize
    }

    size_t new_capacity = v.capacity();
    while (new_capacity < new_size) {
        new_capacity *= 2;
    }

    v.reserve(new_capacity);
}

int main(int argc, char* argv[]) {
    const size_t size = 1000000000;    
    std::vector<int> b;
    b.reserve(1); // Initial reserve to avoid multiple small reallocations

    for (size_t i = 0; i < size; i++) {
        exponential_resize(b, i + 1); // Ensure capacity for the next element
        b.push_back(i);
    }

    return 0;
}
