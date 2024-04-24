#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void parseLine(const std::string& line, float& x, float& y, float& z) {
    std::istringstream iss(line);
    std::vector<float> values;
    float value;
    while (iss >> value) {
        values.push_back(value);
        if (iss.peek() == ' ') { // Check if there's a space after the float
            iss.ignore();
        }
    }
    if (values.size() != 3) {
        // Handle incorrect number of floats in the line
        // Throw an exception or handle the error accordingly
    }
    x = values[0];
    y = values[1];
    z = values[2];
}

int main() {
    std::ifstream file("your_file.txt");
    std::string line;
    while (std::getline(file, line)) {
        float x, y, z;
        parseLine(line, x, y, z);
        // Use the parsed floats as needed
        // ...
    }
    return 0;
}
