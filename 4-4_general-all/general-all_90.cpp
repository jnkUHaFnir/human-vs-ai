#include <iostream>
#include <string>

int main() {
    const char *input = "12345";
    
    try {
        int result = std::stoi(input);
        std::cout << "Parsed integer: " << result << std::endl;
    } catch(const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    } catch(const std::out_of_range& e) {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }

    return 0;
}
