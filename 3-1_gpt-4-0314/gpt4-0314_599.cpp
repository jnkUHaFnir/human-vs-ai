In maths, which of these numbers is not referred to as a square number?
A: 0
B: 1
C: 2
D: 4
C

What is the square root of 9?
A: 1
B: 2
C: 3
D: 4
C
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Question
{
    std::string question;
    std::string answers[4];
    std::string correctAnswer;
};

int main()
{
    std::vector<Question> quizQuestions;

    // Read questions and answers from the text file
    std::ifstream file("questions.txt");

    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            Question q;
            q.question = line;
            for (int i = 0; i < 4; ++i)
            {
                std::getline(file, line);
                q.answers[i] = line;
            }
            std::getline(file, line);
            q.correctAnswer = line[0];
            quizQuestions.push_back(q);
        }
        file.close();
    }
    else
    {
        std::cerr << "Unable to open file" << std::endl;
    }

    // Run the quiz
    for (const Question &q : quizQuestions)
    {
        Play_sound_function_here(); // Put your PlaySound function here
        std::cout << q.question << std::endl;
        for (int i = 0; i < 4; ++i)
        {
            Sleep(2000);
            std::cout << q.answers[i] << std::endl;
        }

        std::string answer;
        std::cout << "So, A, B, C or D?";
        std::cin >> answer;
        if (answer == q.correctAnswer)
        {
            std::cout << "That's correct!" << std::endl;
            Play_sound_function_here(); // Put your PlaySound function here
        }
        else
        {
            std::cout << "That's incorrect." << std::endl;
        }
    }
    return 0;
}
