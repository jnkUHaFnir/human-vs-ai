#include<vector>
#include<cmath>

int main() {
    const int size = 1000000000;
    std::vector<int> b;
    b.reserve(size);

    // Define custom exponential growth factor for vector resizing
    const double growth_factor = 1.5; // Choose any growth factor you find suitable

    for(int i = 0; i < size; i++) {
        if (b.size() == b.capacity()) {
            // Calculate new capacity using exponential growth factor
            size_t new_capacity = static_cast<size_t>(std::ceil(b.capacity() * growth_factor));

            // Reserve new capacity
            b.reserve(new_capacity);
        }
        b.push_back(i);
    }

    return 0;
}
