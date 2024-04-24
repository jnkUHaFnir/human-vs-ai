#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
    int countWords = 0, countNumbers = 0;

    std::ifstream file("input1.txt");
    std::string line;

    while (std::getline(file, line)) {
        std::replace_if(line.begin(), line.end(), [](char c) { return c == '.' || c == ','; }, ' '); // replace commas and periods with spaces

        std::istringstream iss(line);
        std::string token;

        while (iss >> token) {
            if (!token.empty() && std::all_of(token.begin(), token.end(), [](char c) { return std::isdigit(c) || c == '+' || c == '-'; })) {
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
