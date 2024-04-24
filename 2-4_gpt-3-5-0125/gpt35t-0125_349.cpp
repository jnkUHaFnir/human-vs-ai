#include <iostream>
#include <string>

int main() {
    char* str = "12345";
    try {
        int num = std::stoi(str);
        std::cout << "Parsed integer: " << num << std::endl;
    } catch(std::invalid_argument const &e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    } catch(std::out_of_range const &e) {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }

    return 0;
}
