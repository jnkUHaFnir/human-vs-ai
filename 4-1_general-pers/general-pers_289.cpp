#include <iostream>
#include <vector>
#include <cstring>

int main() {
    std::vector<char*> v = {"apple", "orange", "apple", "banana", "orange"};
    std::vector<char*> duplicates;

    for (auto iter = v.begin(); iter != v.end(); ++iter) {
        char* aString = *iter;
        for (auto iter2 = iter + 1; iter2 != v.end(); ++iter2) {
            if (strcmp(aString, *iter2) == 0) {
                duplicates.push_back(*iter2);
            }
        }
    }

    for (char* dup : duplicates) {
        v.erase(std::remove(v.begin(), v.end(), dup), v.end());
        delete[] dup; // Remember to free memory for the removed duplicate
    }

    // Output the deduplicated vector
    for (auto str : v) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    return 0;
}
