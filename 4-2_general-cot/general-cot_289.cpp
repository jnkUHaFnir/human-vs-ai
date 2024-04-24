#include <iostream>
#include <vector>
#include <cstring>

int main() {
    std::vector<char*> v = {"apple", "banana", "apple", "orange", "banana"};

    for (auto iter = v.begin(); iter != v.end(); ) {
        bool duplicateFound = false;
        for (auto iter2 = iter + 1; iter2 != v.end(); ) {
            if (strcmp(*iter, *iter2) == 0) {
                iter2 = v.erase(iter2);
                duplicateFound = true;
            } else {
                ++iter2;
            }
        }

        if (duplicateFound) {
            iter = v.erase(iter);
        } else {
            ++iter;
        }
    }

    // Print the vector without duplicates
    for (const auto& str : v) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    return 0;
}
