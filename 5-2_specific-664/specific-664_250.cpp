#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    std::ifstream file("your_file.txt");
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        float x, y, z;

        if (!(iss >> x >> y >> z)) {
            std::cerr << "Error parsing line: " << line << std::endl;
            continue;
        }

        // Do something with x, y, z (e.g., print)
        std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
    }

    return 0;
}
