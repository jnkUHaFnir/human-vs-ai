#include <iostream>
#include <string>

int main() {
    char s[] = "12345";
    try {
        int i = std::stoi(s);
        std::cout << "Parsed integer: " << i << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error parsing integer: " << e.what() << std::endl;
    }
    return 0;
}
