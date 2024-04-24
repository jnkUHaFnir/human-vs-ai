#include<vector>

int main() {
    const unsigned long long size = 1000000000;

    std::vector<int> b(size);
    for(unsigned long long i = 0; i < size; i++) {
        b[i] = static_cast<int>(i); // Cast literal to integer
    }

    return 0;
}
#include<vector>

int main() {
    const unsigned long long size = 1000000000;
    std::vector<int> b;
    b.reserve(size); // Reserve space to avoid reallocations

    for(unsigned long long i = 0; i < size; i++) {
        b.push_back(static_cast<int>(i)); // Cast literal to integer
    }

    return 0;
}
#include<vector>

int main() {
    const unsigned long long size = 1000000000;
    std::vector<int> b;
    b.reserve(size); // Reserve space to avoid reallocations

    for(unsigned long long i = 0; i < size; i++) {
        b.push_back(static_cast<int>(i)); // Cast literal to integer
    }

    return 0;
}
int main() {
    const unsigned long long size = 1000000000;
    int* a = new int[size]();
    for(unsigned long long i = 0; i < size; i++) {
        a[i] = static_cast<int>(i); // Cast literal to integer
    }
    delete[] a; // Use delete[] for arrays

    return 0;
}
#include <cstdlib>

int main() {
    const unsigned long long size = 1000000000;
    int* a = static_cast<int*>(malloc(size * sizeof(int)));
    int next_power = 1;

    for(unsigned long long i = 0; i < size; i++) {
        a[i] = static_cast<int>(i); // Cast literal to integer
        if(i == next_power - 1) {
            next_power *= 2;
            a = static_cast<int*>(realloc(a, next_power * sizeof(int)));
        }
    }

    free(a); // Use free for memory deallocation

    return 0;
}
