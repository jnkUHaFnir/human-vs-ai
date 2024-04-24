#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    std::ostringstream oss;
    int num = 42;
    float pi = 3.14;
    std::string message = "Hello, World!";

    oss << "Number: " << num << std::endl;
    oss << "Pi value: " << pi << std::endl;
    oss << "Message: " << message << std::endl;

    std::ofstream file("output.txt");
    if (file.is_open()) {
        file << oss.str();
        file.close();
        std::cout << "Data written to file successfully!" << std::endl;
    } else {
        std::cerr << "Unable to open file!" << std::endl;
    }

    return 0;
}
