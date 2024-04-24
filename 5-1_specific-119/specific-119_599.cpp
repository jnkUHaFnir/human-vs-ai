"In maths, which of these numbers is not referred to as a square number?",A: 0,B: 1,C: 2,D: 4,C
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

// Function to load questions and answers from a text file
void loadQuestions(std::vector<std::pair<std::string, std::string>>& questions) {
    std::ifstream file("questions.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string question, answer;
            std::getline(iss, question, ',');
            std::getline(iss, answer, ',');
            questions.push_back(std::make_pair(question, answer));
        }
        file.close();
    } else {
        std::cerr << "Unable to open file." << std::endl;
    }
}

int main() {
    std::vector<std::pair<std::string, std::string>> questions;
    loadQuestions(questions);

    for (const auto& q : questions) {
        std::cout << q.first << std::endl;

        // Split answers
        std::istringstream iss(q.second);
        std::string answer;
        while (std::getline(iss, answer, ',')) {
            std::cout << answer << std::endl;
        }

        char userAnswer;
        std::cout << "So, A, B, C or D? ";
        std::cin >> userAnswer;

        if (userAnswer == q.second.back()) {
            std::cout << "Correct!" << std::endl; // Add sound and other logic as needed
        } else {
            std::cout << "Incorrect!" << std::endl; // Provide feedback based on the user's answer
        }
    }

    return 0;
}
