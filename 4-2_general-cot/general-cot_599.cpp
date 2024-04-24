In maths, which of these numbers is not referred to as a square number?
A: 0
B: 1
C: 2
D: 4
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string question, answerA, answerB, answerC, answerD;
    
    std::ifstream file("questions.txt");
    if (file.is_open()) {
        std::getline(file, question);
        std::getline(file, answerA);
        std::getline(file, answerB);
        std::getline(file, answerC);
        std::getline(file, answerD);
        file.close();
    } else {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    std::cout << question << std::endl;
    std::cout << answerA << std::endl;
    // Output other answers...
    
    std::string playerAnswer;
    std::cout << "So, A, B, C or D? ";
    std::cin >> playerAnswer;
    
    if (playerAnswer == "C" || playerAnswer == "c") {
        std::cout << "That's correct, you've won £200!" << std::endl;
        // Play correct sound...
    } else {
        // Play wrong sound...
    }
    
    return 0;
}
