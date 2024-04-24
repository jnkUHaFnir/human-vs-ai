#include <iostream>
#include <string>
#include <stdexcept>

int main() {
    char* str = "12345";
    
    try {
        int num = std::stoi(str);
        std::cout << "Parsed integer: " << num << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}
