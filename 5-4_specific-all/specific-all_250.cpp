#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::ifstream file("your_file.txt");
    std::string line;
    
    while (std::getline(file, line)) {
        std::vector<float> floats; // Store the extracted floats here
        std::istringstream iss(line);
        std::string token;

        while (std::getline(iss, token, ' ')) {
            try {
                float f = std::stof(token);
                floats.push_back(f);
            } catch (const std::invalid_argument& e) {
                std::cerr << "Invalid float value found: " << token << std::endl;
            } catch (const std::out_of_range& e) {
                std::cerr << "Float value out of range: " << token << std::endl;
            }
        }

        // Now 'floats' vector contains the floats extracted from the line
        for (float f : floats) {
            std::cout << f << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
