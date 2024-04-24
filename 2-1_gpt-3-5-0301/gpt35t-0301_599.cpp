#include <fstream>
#include <sstream>
#include <string>
#include <vector>

// Define a struct to hold a single question and its answers
struct Question {
    std::string text;
    std::vector<std::string> answers;
    char correctAnswer;
};

// Read in the questions from a file
std::vector<Question> readQuestionsFromFile(const std::string& filename) {
    std::ifstream infile(filename);

    std::vector<Question> questions;

    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string question, answerA, answerB, answerC, answerD, correctAnswer;

        std::getline(std::getline(iss, question, ','), answerA, ',');
        std::getline(std::getline(iss, answerB, ','), answerC, ',');
        std::getline(std::getline(iss, answerD, ','), correctAnswer, ',');

        Question q;
        q.text = question;
        q.answers = {answerA, answerB, answerC, answerD};
        q.correctAnswer = correctAnswer[0]; // Assumes correctAnswer is a single character

        questions.push_back(q);
    }

    return questions;
}

int main() {
    std::vector<Question> questions = readQuestionsFromFile("questions.txt");

    // Display the second question and its possible answers
    Question& q2 = questions[1]; // The index is 1 since vectors are 0-indexed
    std::cout << q2.text << std::endl;
    for (const auto& answer : q2.answers) {
        std::cout << answer << std::endl;
    }

    // Get the user's answer
    char userAnswer;
    std::cin >> userAnswer;

    // Check if the answer is correct
    if (userAnswer == q2.correctAnswer) {
        std::cout << "That's correct!" << std::endl;
    } else {
        std::cout << "Sorry, that's incorrect." << std::endl;
    }

    return 0;
}