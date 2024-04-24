#include <iostream>
#include <string>

int main() {
    const char* str = "12345";
    
    try {
        int num = std::stoi(str);
        std::cout << "Parsed integer: " << num << std::endl;
    } 
    catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    } 
    catch (const std::out_of_range& e) {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }

    return 0;
}
