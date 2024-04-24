#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

int main(int argc, char* argv[]) {
    int countWords = 0, countNumbers = 0;

    std::ifstream file("input1.txt");

    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string word;

    while (file >> word) {
        // Remove commas and periods from the word
        word.erase(std::remove_if(word.begin(), word.end(), [](unsigned char c) {
            return std::ispunct(c);
        }), word.end());

        // Check if the word is a number
        bool isNumber = true;
        for (char c : word) {
            if (!std::isdigit(c)) {
                isNumber = false;
                break;
            }
        }

        if (isNumber && !word.empty()) {
            countNumbers++;
        } else {
            countWords++;
        }

        std::cout << word << " ";
    }

    std::cout << std::endl;
    std::cout << "Words = " << countWords << "      Numbers = " << countNumbers << std::endl;

    return 0;
}
