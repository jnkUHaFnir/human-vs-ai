#include <unordered_map>
#include <iostream>

std::unordered_map<unsigned long long, std::string> dataMap;

void set(unsigned long long A, char* B) {
    dataMap[A] = B;
}

void get(unsigned long long A) {
    if(dataMap.find(A) != dataMap.end()) {
        std::cout << "Value found for key " << A << ": " << dataMap[A] << std::endl; 
    } else {
        std::cout << "Value not found for key " << A << std::endl;
    }
}

int main() {
    set(12345, "Hello");
    set(67890, "World");
    
    get(12345); // Output: Value found for key 12345: Hello
    get(99999); // Output: Value not found for key 99999
    
    return 0;
}
