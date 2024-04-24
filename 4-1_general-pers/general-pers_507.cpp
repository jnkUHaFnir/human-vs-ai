#include <iostream>
#include <algorithm> // for std::move

template <typename T>
class CustomVector {
private:
    T* data;
    size_t size;
    size_t capacity;

public:
    CustomVector() : data(nullptr), size(0), capacity(0) {}

    ~CustomVector() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (size >= capacity) {
            size_t new_capacity = (capacity == 0) ? 1 : 2 * capacity;
            reserve(new_capacity);
        }
        data[size++] = value;
    }

    void reserve(size_t new_capacity) {
        if (new_capacity <= capacity) {
            return;
        }
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < size; i++) {
            new_data[i] = std::move(data[i]);
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

    size_t getSize() const {
        return size;
    }

    size_t getCapacity() const {
        return capacity;
    }
};

int main() {
    const int size = 1000000000;

    CustomVector<int> b;
    for (int i = 0; i < size; i++) {
        b.push_back(i);
    }

    std::cout << "Size of the custom vector: " << b.getSize() << std::endl;
    std::cout << "Capacity of the custom vector: " << b.getCapacity() << std::endl;

    return 0;
}
