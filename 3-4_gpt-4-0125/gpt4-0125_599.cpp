Question:In maths, which of these numbers is not referred to as a square number?
A:0
B:1
C:2
D:4
Correct:C
--
Question:What is the capital of France?
A:Rome
B:Madrid
C:Berlin
D:Paris
Correct:D
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>
#include <mmsystem.h>

struct Question {
    std::string questionText;
    std::string options[4];
    char correctAnswer;
};

void LoadQuestions(const std::string& filePath, std::vector<Question>& questions) {
    std::ifstream file(filePath);
    std::string line;
    Question currentQuestion;
    int optionIndex = 0;
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.find("Question:") == 0) {
                currentQuestion.questionText = line.substr(9);
            } else if (line.length() == 1 && line >= "A" && line <= "D") {
                currentQuestion.correctAnswer = line[0];
                questions.push_back(currentQuestion);
                currentQuestion = Question();
                optionIndex = 0;
            } else if (line.find("A:") == 0 || line.find("B:") == 0 || line.find("C:") == 0 || line.find("D:") == 0) {
                currentQuestion.options[optionIndex++] = line.substr(2);
            }
        }
        file.close();
    }
}

void AskQuestion(const Question& question) {
    std::cout << question.questionText << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << char('A' + i) << ": " << question.options[i] << std::endl;
    }

    std::string answer;
    std::cout << "So, A, B, C or D?";
    std::cin >> answer;

    if (toupper(answer[0]) == question.correctAnswer) {
        std::cout << "That's correct!" << std::endl;
        // PlaySound(TEXT("Millionaire/correct_answer.wav"), NULL, SND_FILENAME);
    } else {
        std::cout << "Sorry, that's incorrect." << std::endl;
    }
}

int main() {
    std::vector<Question> questions;
    LoadQuestions("questions.txt", questions);
    
    for (const auto& question : questions) {
        AskQuestion(question);
        // Sleep(2000); // Adjust or remove as per your requirement.
    }

    return 0;
}
