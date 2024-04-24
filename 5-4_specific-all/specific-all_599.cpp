In maths, which of these numbers is not referred to as a square number?
A: 0
B: 1
C: 2
D: 4
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::ifstream file("questions.txt");
    
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::vector<std::string> questionsAndAnswers;
    std::string line;
    
    while (std::getline(file, line)) {
        questionsAndAnswers.push_back(line);
    }

    file.close();

    // Display questions and answers
    for (const auto& qa : questionsAndAnswers) {
        std::cout << qa << std::endl;
        Sleep(2000);
    }

    // User input and answer processing can be continued here

    return 0;
}
