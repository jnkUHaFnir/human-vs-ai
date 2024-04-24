#include <vector>

int main(int argc, char * argv[]) {
    const unsigned long long size = 1000000000;
    std::vector<int> b;
    b.reserve(size); // Reserve memory to avoid multiple reallocs

    for(int i = 0; i < size; i++) {
        b.push_back(i);
    }

    return 0;
}
