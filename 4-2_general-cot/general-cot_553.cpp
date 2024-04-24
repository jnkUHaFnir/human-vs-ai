#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

int main() {
    int countWords = 0, countNumbers = 0;

    std::ifstream file("input1.txt");
    std::string line;

    // Read the file line-by-line
    while (std::getline(file, line)) {
        std::istringstream stream(line);
        std::string word;

        // Tokenize by spaces, commas, and periods
        while (stream >> word) {
            // Remove commas and periods from the word
            word.erase(std::remove_if(word.begin(), word.end(), [](unsigned char c) { return std::ispunct(c); }), word.end());

            // Check if the modified word is a number
            if (!word.empty() && std::all_of(word.begin(), word.end(), ::isdigit)) {
                countNumbers++;
            } else {
                countWords++;
            }

            std::cout << word << " ";
        }
    }

    std::cout << std::endl;
    std::cout << "Words = " << countWords << "      Numbers = " << countNumbers << std::endl;

    return 0;
}
