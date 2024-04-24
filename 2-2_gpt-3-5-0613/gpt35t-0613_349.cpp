#include <iostream>
#include <string>

int main() {
    try {
        const char* str = "123";
        int result = std::stoi(str);
        std::cout << "Parsed int: " << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Invalid argument: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Out of range: " << e.what() << std::endl;
    }

    return 0;
}
