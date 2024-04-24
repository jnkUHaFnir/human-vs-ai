Question: In maths, which of these numbers is not referred to as a square number?
Answers:
A: 0
B: 1
C: 2
D: 4
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("questions.txt"); // Open the text file
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.find("Question:") != std::string::npos) {
            std::cout << line << std::endl; // Display the question
        } else if (line.find("Answers:") != std::string::npos) {
            while (std::getline(file, line) && line != "") {
                std::cout << line << std::endl; // Display each answer
            }
        }
    }

    file.close(); // Close the file

    std::string answer;
    std::cout << "So, A, B, C or D?";
    std::cin >> answer;

    if (answer == "C" || answer == "c") {
        std::cout << "That's correct, you've won \x9C200!" << std::endl;
        // Play correct sound
    }

    return 0;
}
