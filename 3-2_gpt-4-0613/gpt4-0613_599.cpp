In maths, which of these numbers is not referred to as a square number?
A: 0
B: 1
C: 2
D: 4
C
#include <fstream>
#include <vector>

struct Question {
    std::string question;
    std::vector<std::string> options;
    std::string correctAnswer;
};

Question readQuestion(const std::string& filepath) {
    std::ifstream file(filepath);
    Question question;

    // First line is the question
    std::getline(file, question.question);

    // Next four lines are the options
    for (int i = 0; i < 4; ++i) {
        std::string option;
        std::getline(file, option);
        question.options.push_back(option);
    }

    // Final line is the correct answer
    std::getline(file, question.correctAnswer);

    return question;
}
Question question = readQuestion("ques.txt");

std::cout << question.question << std::endl;
for (const auto& option : question.options) {
    std::cout << option << std::endl;
}
Sleep(2000);

std::string answer;
std::cout << "So, A, B, C or D?";
std::cin >> answer;

if (answer == question.correctAnswer) {
    // etc.
}
``` 

This implementation assumes each question/answer set has its own text file, but you can easily modify it to have multiple question/answer sets in the same file, separated by some delimiter. If you want all the questions in one file then you need to separate them by some delimiters and adjust the code accordingly to read each question separately. Also, note that there's no error handling, you might want to add that considering the case if, for example, the file does not exist.

