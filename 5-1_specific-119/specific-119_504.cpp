#include <iostream>
#include <vector>

template <typename T>
class GeometricVector : public std::vector<T> {
public:
    void push_back(const T& value) {
        if (this->size() == this->capacity()) {
            if (this->capacity() > 0) {
                this->reserve(this->capacity() * 2);
            } else {
                this->reserve(1); // start with capacity 1
            }
        }
        std::vector<T>::push_back(value);
    }
};

int main() {
    const unsigned long long size = 1000000000;

    GeometricVector<int> b;
    for (int i = 0; i < size; i++) {
        b.push_back(i);
    }

    return 0;
}
