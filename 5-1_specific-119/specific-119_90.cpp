#include <iostream>
#include <string>

int main() {
    char str[] = "12345";
    int result;
    try {
        result = std::stoi(str);
        std::cout << "Parsed integer: " << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range error: " << e.what() << std::endl;
    }
    
    return 0;
}
