#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::ifstream file("questions.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    std::string line;
    std::vector<std::string> questions;
    std::vector<std::string> answers;
    std::string correctAnswer;

    while (std::getline(file, line)) {
        if (line == "[Question]") {
            std::getline(file, line); // Read the question
            questions.push_back(line);
        }
        else if (line == "[Answers]") {
            while (std::getline(file, line) && line != "[CorrectAnswer]") {
                answers.push_back(line);
            }
        }
        else if (line == "[CorrectAnswer]") {
            std::getline(file, line); // Read the correct answer
            correctAnswer = line;
        }
    }

    file.close();

    // Display the question and answers
    std::cout << questions[0] << std::endl;
    for (const auto& answer : answers) {
        std::cout << answer << std::endl;
    }

    // Get user input
    std::string userAnswer;
    std::cout << "So, A, B, C, or D?";
    std::cin >> userAnswer;

    // Check user answer
    if (userAnswer == correctAnswer) {
        std::cout << "That's correct!" << std::endl;
    } else {
        std::cout << "Incorrect. The correct answer is: " << correctAnswer << std::endl;
    }

    return 0;
}
