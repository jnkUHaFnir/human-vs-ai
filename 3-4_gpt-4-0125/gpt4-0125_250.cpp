#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

int main() {
    std::ifstream file("your_file.txt"); // Replace with your actual file path
    std::string line;
    std::vector<float> values;

    if (!file.is_open()) {
        std::cerr << "Failed to open file\n";
        return -1;
    }

    while (std::getline(file, line)) {
        std::istringstream lineStream(line);
        float x, y, z;
        if (lineStream >> x >> y >> z) {
            values.push_back(x);
            values.push_back(y);
            values.push_back(z);
            // Process or store the floats as needed
        } else {
            std::cerr << "Failed to parse line: " << line << '\n';
        }
    }

    file.close();
    // Now, values vector contains all the floats. You can process them as needed.

    return 0;
}
