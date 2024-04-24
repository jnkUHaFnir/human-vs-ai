#include <iostream>
#include <vector>
#include <cstring>

int main() {
    std::vector<char *> v = {"apple", "banana", "apple", "orange", "banana", "peach"};

    for (auto iter = v.begin(); iter != v.end(); ) {
        char *aString = *iter;
        auto current = iter + 1;
        while (current != v.end()) {
            if (strcmp(aString, *current) == 0) {
                current = v.erase(current);
            } else {
                ++current;
            }
        }
        ++iter;
    }

    // Print the modified vector
    for (const auto& str : v) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    return 0;
}
