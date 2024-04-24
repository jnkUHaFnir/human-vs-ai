In maths, which of these numbers is not referred to as a square number?
A: 0
B: 1
C: 2
D: 4

What is the capital of France?
A: London
B: Paris
C: Berlin
D: Rome
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::ifstream file("questions.txt");

    if (file.is_open()) {
        std::string line;
        std::vector<std::string> questions;
        
        while (std::getline(file, line)) {
            questions.push_back(line);
        }

        file.close();

        // Display questions and answers
        for (int i = 0; i < questions.size(); i += 5) {
            std::cout << questions[i] << std::endl;
            for (int j = i + 1; j < i + 5; j++) {
                std::cout << questions[j] << std::endl;
            }

            // Here you can implement the logic for getting user input and checking the answer
            // You can also play sounds and display messages depending on the answer
            // You can have a loop to repeat the process for all questions in the file
        }
    } else {
        std::cout << "Error opening file." << std::endl;
    }

    return 0;
}
