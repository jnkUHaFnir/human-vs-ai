#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <mmsystem.h>

#pragma comment(lib, "Winmm.lib")

bool isValidAnswer(const std::string& ans) {
    return ans == "A" || ans == "B" || ans == "C" || ans == "D" || ans == "a" || ans == "b" || ans == "c" || ans == "d";
}

int main() {
    std::ifstream file("questions.txt"); // Open the file containing questions and answers
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string question;
    std::string answerC;
    std::string answer1;
    std::string answer2;
    std::string answer3;

    while (std::getline(file, question) && std::getline(file, answer1) &&
           std::getline(file, answer2) && std::getline(file, answer3) && std::getline(file, answerC)) {
        std::cout << question << std::endl;
        Sleep(2000);
        std::cout << "A: " << answer1 << std::endl;
        Sleep(2000);
        std::cout << "B: " << answer2 << std::endl;
        Sleep(2000);
        std::cout << "C: " << answer3 << std::endl;
        Sleep(2000);
        std::cout << "D: " << answerC << std::endl;
        Sleep(2000);

        std::string userAnswer;
        bool validAnswer = false;
        while (!validAnswer) {
            std::cout << "So, A, B, C or D? ";
            std::cin >> userAnswer;

            if (isValidAnswer(userAnswer)) {
                validAnswer = true;
            } else {
                std::cout << "Invalid answer. Please choose A, B, C, or D." << std::endl;
            }
        }

        if (userAnswer == answerC || userAnswer == answerC) {
            std::cout << "Correct answer!" << std::endl;
            PlaySound(TEXT("correct.wav"), NULL, SND_FILENAME);
            Sleep(2000);
        } else {
            std::cout << "Incorrect answer. The correct answer was: " << answerC << std::endl;
            PlaySound(TEXT("incorrect.wav"), NULL, SND_FILENAME);
            Sleep(2000);
        }
    }

    file.close(); // Close the file

    return 0;
}
Question 1
Answer 1
Answer 2
Answer 3
Correct Answer
