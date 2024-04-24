#include <vector>

// Function to push elements into a vector with exponential growth
template<typename T>
void push_back_exponential(std::vector<T> &vec, const T &value) {
    if (vec.empty()) {
        vec.push_back(value);
    } else if (vec.size() == vec.capacity()) {
        vec.reserve(vec.capacity() * 2); // Double the capacity
        vec.push_back(value);
    } else {
        vec.push_back(value);
    }
}

int main(int argc, char *argv[]) {
    const int size = 1000000000;
    std::vector<int> b;
    b.reserve(size); // Reserve initial size

    for (int i = 0; i < size; i++) {
        push_back_exponential(b, i);
    }

    return 0;
}
