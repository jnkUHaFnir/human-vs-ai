#include <iostream>
#include <vector>
#include <cstring>

int main() {
    std::vector<char*> v = { "apple", "banana", "apple", "cherry", "banana", "apple" };

    std::vector<char*> uniqueElements;
    for (auto iter = v.begin(); iter != v.end(); iter++) {
        bool isDuplicate = false;
        for (auto uniqueIter = uniqueElements.begin(); uniqueIter != uniqueElements.end(); uniqueIter++) {
            if (strcmp(*iter, *uniqueIter) == 0) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            uniqueElements.push_back(*iter);
        }
    }

    v = uniqueElements;

    // Output to verify the vector
    for (auto elem : v) {
        std::cout << elem << std::endl;
    }

    return 0;
}
