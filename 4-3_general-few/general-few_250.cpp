#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    std::ifstream file("your_file.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        float x, y, z;
        if (!(iss >> x >> y >> z)) {
            std::cerr << "Error parsing line: " << line << std::endl;
            continue;
        }
        // Now you have the floats x, y, z from the line
        std::cout << "Parsed values: " << x << ", " << y << ", " << z << std::endl;
    }

    file.close();
    return 0;
}
