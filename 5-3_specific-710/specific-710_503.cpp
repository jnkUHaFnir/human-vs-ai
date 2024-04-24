#include <vector>

int main(int argc, char *argv[]) {
    const int size = 1000000000;
    std::vector<int> b;
    int capacity = 1;

    for (int i = 0; i < size; i++) {
        b.push_back(i);

        if (b.size() == capacity) {
            capacity *= 2;
            b.reserve(capacity);
        }
    }

    return 0;
}
