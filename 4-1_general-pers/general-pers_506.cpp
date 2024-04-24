#include <iostream>

template <typename T>
class GeometricVector {
private:
    T* arr;
    size_t capacity;
    size_t size;

public:
    GeometricVector() : capacity(1), size(0) {
        arr = new T[capacity];
    }

    ~GeometricVector() {
        delete[] arr;
    }

    void push_back(const T& value) {
        if (size == capacity) {
            capacity *= 2;
            T* new_arr = new T[capacity];
            for (size_t i = 0; i < size; ++i) {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
        }
        arr[size++] = value;
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

    GeometricVector<int> b;
    for (int i = 0; i < size; i++) {
        b.push_back(i);
    }

    std::cout << "Size: " << b.getSize() << std::endl;
    std::cout << "Capacity: " << b.getCapacity() << std::endl;

    return 0;
}
