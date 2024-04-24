#include <vector>

int main(int argc, char *argv[]) {
    const int size = 1000000000;
    std::vector<int> b;
    const int chunkSize = 1000000; // Adjust chunk size as needed

    b.reserve(chunkSize); // Start with an initial capacity

    for (int i = 0; i < size; i++) {
        b.push_back(i);

        if (b.size() % chunkSize == 0) {
            b.reserve(b.size() + chunkSize); // Add more capacity in chunks
        }
    }

    return 0;
}
