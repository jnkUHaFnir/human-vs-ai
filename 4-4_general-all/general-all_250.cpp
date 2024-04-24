#include <cstdio>
#include <fstream>

int main() {
    std::ifstream file("input.txt");

    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    float x, y, z;
    std::string line;

    while (std::getline(file, line)) {
        if (sscanf(line.c_str(), "%f %f %f", &x, &y, &z) == 3) {
            // Process the parsed floating-point values x, y, z here
        } else {
            std::cerr << "Error parsing line: " << line << std::endl;
        }
    }

    file.close();
    return 0;
}
