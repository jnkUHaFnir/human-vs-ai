#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string name;
    
    std::regex pattern("[0-9a-zA-Z]+");
    
    std::cout << "Enter a string: ";
    std::getline(std::cin, name);
    
    if (std::regex_match(name, pattern)) {
        std::cout << "Matched" << std::endl;
    } else {
        std::cout << "Invalid" << std::endl;
    }
    
    return 0;
}
