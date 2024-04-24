Q: In maths, which of these numbers is not referred to as a square number?
A: 0
B: 1
C: 2
D: 4
CorrectAnswer: C
#include <fstream> // for file operations
#include <sstream> // for string manipulation
std::ifstream file("questions.txt"); // Open the text file for reading
std::string line, question, answer1, answer2, answer3, answer4, correctAnswer;

std::getline(file, line); // Read the entire line
question = line.substr(3); // Extract the question from the line

// Read and assign the answers from the text file
std::getline(file, line);
answer1 = line.substr(3);

std::getline(file, line);
answer2 = line.substr(3);

std::getline(file, line);
answer3 = line.substr(3);

std::getline(file, line);
answer4 = line.substr(3);

std::getline(file, line); // Read the correct answer line
correctAnswer = line.substr(13); // Extract the correct answer from the line

file.close(); // Close the file after reading
std::cout << question << std::endl;
Sleep(2000);
std::cout << "A: " << answer1 << std::endl;
Sleep(2000);
std::cout << "B: " << answer2 << std::endl;
Sleep(2000);
std::cout << "C: " << answer3 << std::endl;
Sleep(2000);
std::cout << "D: " << answer4 << std::endl;
Sleep(2000);

// Take user input for the answer
std::string userAnswer;
std::cout << "So, A, B, C or D?";
std::cin >> userAnswer;

if (userAnswer == correctAnswer)
{
    std::cout << "That's correct, you've won " << char(156) << "200!" << std::endl;
    PlaySound(TEXT("Millionaire/£100correct.wav"), NULL, SND_FILENAME);
    Sleep(2000);
}
