#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    std::ifstream file("your_file.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::string line;
    float x, y, z;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        if (!(iss >> x >> y >> z)) {
            std::cerr << "Error parsing line: " << line << std::endl;
            continue;
        }

        // Do something with x, y, z
        // For example, you can print them
        std::cout << "Parsed values: " << x << " " << y << " " << z << std::endl;
    }

    file.close();

    return 0;
}
