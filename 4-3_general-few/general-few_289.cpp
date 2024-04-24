#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<char*> v = {"hello", "world", "hello", "cpp", "world"};

    std::sort(v.begin(), v.end());
    auto last = std::unique(v.begin(), v.end());
    v.erase(last, v.end());

    // Print the vector without duplicates
    for (const auto& s : v) {
        std::cout << s << " ";
    }

    return 0;
}
