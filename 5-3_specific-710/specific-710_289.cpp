#include <iostream>
#include <vector>
#include <set>
#include <cstring>

int main() {
    std::vector<char*> v = {"apple", "banana", "apple", "cherry", "banana"};
    std::set<std::string> uniqueStrings;

    for (auto str : v) {
        if (uniqueStrings.find(str) == uniqueStrings.end()) {
            uniqueStrings.insert(str);
        }
    }

    // Clear the original vector
    v.clear();

    // Update the vector with unique elements
    for (const auto& str : uniqueStrings) {
        v.push_back(strdup(str.c_str())); // strdup to avoid potential issues with memory management
    }

    // Output the unique elements in the vector
    for (const auto& str : v) {
        std::cout << str << std::endl;
    }

    // Free memory allocated by strdup
    for (auto str : v) {
        free(str);
    }

    return 0;
}
