#include <iostream>
#include <vector>
#include <cstring>

int main() {
    std::vector<char *> v = {"hello", "world", "hello", "apple", "world"};

    for (auto iter = v.begin(); iter != v.end(); ++iter) {
        char *aString = *iter;
        auto nextIter = iter + 1;
        while (nextIter != v.end()) {
            if (strcmp(aString, *nextIter) == 0) {
                delete[] *nextIter;
                nextIter = v.erase(nextIter); // update nextIter after erasing
            } else {
                ++nextIter;
            }
        }
    }

    // Output the elements of the vector after removing duplicates
    for (const auto &str : v) {
        std::cout << str << " ";
    }

    // Don't forget to deallocate memory for remaining elements
    for (auto str : v) {
        delete[] str;
    }

    return 0;
}
