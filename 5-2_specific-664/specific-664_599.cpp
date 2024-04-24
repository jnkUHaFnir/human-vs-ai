[Question]
In maths, which of these numbers is not referred to as a square number?
[Answers]
A: 0
B: 1
C: 2
D: 4
[Correct Answer]
C
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Function to read quiz questions and answers from a text file
bool readQuizFromFile(const std::string& filename, std::vector<std::string>& questions, std::vector<std::string>& answers, std::vector<char>& correctAnswers) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return false;
    }

    std::string line;
    std::string currentSection;
    while (std::getline(file, line)) {
        if (line == "[Question]") {
            currentSection = "Question";
        } else if (line == "[Answers]") {
            currentSection = "Answers";
        } else if (line == "[Correct Answer]") {
            currentSection = "Correct Answer";
        } else {
            if (currentSection == "Question") {
                questions.push_back(line);
            } else if (currentSection == "Answers") {
                answers.push_back(line);
            } else if (currentSection == "Correct Answer") {
                if (line.length() > 0) {
                    correctAnswers.push_back(line[0]);
                }
            }
        }
    }

    file.close();
    return true;
}

int main() {
    std::vector<std::string> questions;
    std::vector<std::string> answers;
    std::vector<char> correctAnswers;

    if (readQuizFromFile("quiz_questions.txt", questions, answers, correctAnswers)) {
        // Display questions and answers
        for (size_t i = 0; i < questions.size(); ++i) {
            std::cout << "Question: " << questions[i] << std::endl;

            std::cout << "Answers:" << std::endl;
            std::cout << answers[i] << std::endl;

            char answer;
            std::cout << "Enter your answer (A, B, C, D): ";
            std::cin >> answer;

            if (answer == correctAnswers[i]) {
                std::cout << "Correct answer!" << std::endl;
            } else {
                std::cout << "Incorrect answer!" << std::endl;
            }
        }
    }

    return 0;
}
