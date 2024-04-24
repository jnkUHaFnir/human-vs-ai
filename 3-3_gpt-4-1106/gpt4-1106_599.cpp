What is the capital of France?
A: Paris
B: Rome
C: Madrid
D: Berlin
Answer: A

In maths, which of these numbers is not referred to as a square number?
A: 0
B: 1
C: 2
D: 4
Answer: C

...etc...
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Question {
    std::string questionText;
    std::string options[4];
    char correctAnswer;
};

std::vector<Question> loadQuestionsFromFile(const std::string& filepath) {
    std::vector<Question> questions;
    std::ifstream file(filepath);
    std::string line;
    Question q;

    while (getline(file, line)) {
        if (!line.empty()) {
            q.questionText = line;
            
            for (int i = 0; i < 4; ++i) {
                getline(file, q.options[i]);
            }
            
            getline(file, line); // Skip the "Answer: " part
            q.correctAnswer = line.back();
            questions.push_back(q);
        }
    }
    file.close();
    return questions;
}

int main() {
    std::vector<Question> questions = loadQuestionsFromFile("questions.txt");

    // Now you have all your questions and answers loaded.
    for (const auto& question : questions) {
        // Display the question and options.
        std::cout << question.questionText << std::endl;
        for (const auto& option : question.options) {
            std::cout << option << std::endl;
        }

        // Ask the user for their answer.
        std::string userAnswer;
        std::cout << "So, A, B, C or D? ";
        std::cin >> userAnswer;

        if (toupper(userAnswer[0]) == question.correctAnswer) {
            std::cout << "That's correct!" << std::endl;
        } else {
            std::cout << "That's incorrect. The correct answer is " << question.correctAnswer << "." << std::endl;
        }
        // You might want to add some delay or clear the screen here before the next question.
    }

    // ... Rest of your code ...
}
