#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

int main() {

    int countWords = 0, countNumbers = 0;
    std::ifstream file("input1.txt");
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;

        while (iss >> token) {
            bool isNumber = true;

            for (char& c : token) {
                if (!isdigit(c) && c != '.' && c != ',') {
                    isNumber = false;
                    break;
                }
            }

            if (isNumber) {
                countNumbers++;
            } else {
                countWords++;
            }

            std::cout << token << " ";
        }
    }

    std::cout << std::endl;
    std::cout << "Words = " << countWords << "      Numbers = " << countNumbers << std::endl;

    return 0;
}
