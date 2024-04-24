#include <iostream>
#include <vector>
#include <cstring>

int main() {
    std::vector<char *> v = {"apple", "orange", "apple", "banana", "orange"};

    std::vector<char *> uniqueStrings;
    for (auto iter = v.begin(); iter != v.end(); iter++) {
        char *aString = *iter;
        bool isDuplicate = false;
        for (const char *str : uniqueStrings) {
            if (strcmp(aString, str) == 0) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            uniqueStrings.push_back(aString);
        }
    }

    // Output unique strings
    for (const char *str : uniqueStrings) {
        std::cout << str << std::endl;
    }

    return 0;
}
