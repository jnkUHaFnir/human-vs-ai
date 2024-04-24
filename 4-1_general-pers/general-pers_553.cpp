#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>

bool isNumber(const std::string& s) {
    return !s.empty() && std::find_if(s.begin(), s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}

int main(int argc, char* argv[]) {
    int countWords = 0, countNumbers = 0;

    std::ifstream file("input1.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string word;

        while (ss >> word) {
            std::string cleanedWord;
            for (char c : word) {
                if (std::isalnum(c) || c == ',' || c == '.') {
                    cleanedWord += c == ',' || c == '.' ? ' ' : c; // Replace commas and periods with spaces
                }
            }

            std::stringstream wordSS(cleanedWord);
            while (wordSS >> word) {
                if (isNumber(word)) {
                    countNumbers++;
                } else {
                    countWords++;
                }
                std::cout << word << " ";
            }
        }
    }

    std::cout << std::endl;
    std::cout << "Words = " << countWords << "      Numbers = " << countNumbers << std::endl;

    return 0;
}
