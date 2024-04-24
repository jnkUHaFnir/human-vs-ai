In maths, which of these numbers is not referred to as a square number?;A: 0;B: 1;C: 2;D: 4;C
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::ifstream inputFile("questions.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string line;
    std::vector<std::string> questions;
    while (std::getline(inputFile, line)) {
        questions.push_back(line);
    }

    // Display questions and answers fetched from the file
    for (const std::string& qna : questions) {
        std::cout << qna << std::endl;
    }

    inputFile.close();
    return 0;
}
