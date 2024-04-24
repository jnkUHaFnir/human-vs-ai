#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<unsigned long long, std::string> myMap;

void set(unsigned long long A, const char* B) {
    myMap[A] = std::string(B); // In C++11 and later, this is typically O(1), assuming a good hash function and low collision rate
}

const char* get(unsigned long long A) {
    auto iter = myMap.find(A); // Again O(1) on average
    if (iter != myMap.end()) // If the key was found
        return iter->second.c_str(); 
    return nullptr; // If the key was not found, return NULL (or some other indicator)
}

int main() {
    // Example usage
    set(100, "example");
    const char* result = get(100);
    
    if (result != nullptr)
        std::cout << "Got value: " << result << std::endl;
    else
        std::cout << "Value not found." << std::endl;
        
    return 0;
}
